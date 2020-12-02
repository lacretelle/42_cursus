import React, {useState, useEffect, useContext} from 'react';
import axios from 'axios';
import {socket} from '../store.js';
import { SearchStore } from '../search';
import { Store } from '../store';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faCircle, faCommentAlt } from '@fortawesome/free-solid-svg-icons';
import '../css/chat.css';

export default function Chat() {
	const { state } = useContext(Store);
	const { search } = useContext(SearchStore);
	const [chaters, setChaters] = useState(search.matchs);
	const [chatWindow, setChatWindow] = useState([]);
	const [text, setText] = useState({});
	const [messCounter, setMessCounter] = useState([]);
	const [error, setError] = useState(null);
	let usersDisplay = document.getElementById('chatUsers');

	//GETTING NAME AND MAIN PIC FROM DATABASE BASED ON OUR MATCHS
	useEffect(() => {
		async function fetchChatersName(ids) {
			try {
				let res = await axios.get(`user/others/chat/${ids}`);
				if (res.data)
				{
					let idBlocked = search.blocks.map(e => e.id_blocked);
					res.data = res.data.filter(e => !idBlocked.includes(e.id_user));
					setChaters(res.data);
				}
			} catch (err) {
				//console.error(err);
				setError('Une erreur est survenue.');
			}
		}
		if (search.matchs.length > 0)
		{
			let ids = search.matchs.map(e => {
				if (e.id_user1 !== state.id_session)
					return e.id_user1;
				else
					return e.id_user2;
			}).join(',');
			fetchChatersName(ids);
		}
		return () => {
			socket.removeListener('getSockerUsers');
		};
	}, [search.matchs, state.id_session, search.blocks])

	//SETTING INCOMING MESSAGE
	useEffect(() => {
		socket.on('mess', (data) => {
			let i = chatWindow.findIndex(e => (e.id_user === data.id_author));
			if(i > -1)
			{
				let tmpChatWindow = [...chatWindow];
				tmpChatWindow[i].messages.push(data);
				setChatWindow(tmpChatWindow);
			}
			else
			{
				i = messCounter.findIndex(e => (e.id_author === data.id_author));
				let tmp = [...messCounter];
				if (i > -1)
					tmp[i].count = tmp[i].count + 1;
				else
				{
					i = 0;
					tmp.push({id_author: data.id_author, count: 1});
				}
				setMessCounter(tmp);
				setChaters(chaters.map(e => {
					if (e.id_user === data.id_author)
						return {...e, newmess: tmp[i].count}
					else
						return e
				}));
			}
		});
		socket.on('getSocketUsers', function(data) {
			let tmp = chaters.map(e => {
				if (data.find(f => f === e.id_user))
					e.online = true;
				else
					e.online = false;
				return (e);
			})
			setChaters(tmp);
		});
		let scroll = document.getElementsByClassName('chatWindowContent');
		for (var k = 0; k < scroll.length; k++)
			scroll[k].scrollTop = scroll[k].scrollHeight;
		return (() => {
			socket.removeListener('mess');
			socket.removeListener('getSocketUsers');
		});
	}, [chatWindow, state.id_session, chaters, messCounter])


	//DISLAY ALL CHATERS === MATCHERS(search.matchs)
	function watchChaters() {
		if (usersDisplay.style.display === 'block')
			usersDisplay.style.display = 'none';
		else
		{
			socket.emit('getSocketUsers');
			usersDisplay.style.display = 'block';
		}
		if (messCounter.length > 0)
			setMessCounter([]);
	}

	//OPEN A NEW CHAT WINDOW WITH THE SELECTED CHATERS AND LOAD OLD MESSAGES
	async function openChatWindow(e, data) {
		socket.emit('getSocketUsers');
		let i = chatWindow.findIndex(f => (f.id_user === data.id_user));
		if (i > -1)
			setChatWindow(chatWindow.filter(f => (f.id_user !== data.id_user)));
		else
		{
			let oldMessage = await fetchOldMessage(data.id_user, state.id_session);
			setChatWindow([...chatWindow, {...data, messages: oldMessage }]);
			let tmp = [...chaters];
			let j = tmp.findIndex(e => (e.id_user === data.id_user));
			tmp[j].newmess = 0;
			setChaters(tmp);
		}
	}
	function sendMessage(e, data) {
		e.preventDefault();
		socket.emit('chat-message', {id_author: state.id_session, id_receiver: data.id_user, mess: text[data.id_user]});
		let i = chatWindow.findIndex(e => (e.id_user === data.id_user));
		let tmpChatWindow = [...chatWindow];
		tmpChatWindow[i].messages = [...data.messages, {id_author: state.id_session, mess: text[data.id_user]}];
		setChatWindow(tmpChatWindow);
		setText({...text, [data.id_user]: ''});
	}
	function writeMessage(e, data) {
		setText({...text, [data.id_user]: e.target.value});
	}
	function pressEnter(e, data) {
		if (e.key === 'Enter' && !e.shiftKey)
		{
			e.preventDefault();
			var evt = new MouseEvent("click");
			evt.initMouseEvent("click", true, true, window,
				0, 0, 0, 0, 0, false, false, false, false, 0, null);
			document.getElementById(`submit${data.id_user}`).dispatchEvent(evt);
		}
	}
	function closeWindow(id) {
		setChatWindow(chatWindow.filter(f => (f.id_user !== id)));
	}

	return (
		<>
<div id='chat-bar' onClick={watchChaters}>
	<FontAwesomeIcon icon={faCommentAlt} className='header-icon' />
		{(messCounter.length > 0 && usersDisplay && usersDisplay.style.display !== 'block') && <span className='notif-counter'>
				{messCounter.length}
			</span>}
		</div>
		<ul className='chatWindow-wrapper'>
			<ul id='chatUsers'>
					{chaters.map((e, index) => (<li key={index} className='chatUser' onClick={(f) => {openChatWindow(f, e)}}>
						<img className='chatUserPic' src={e.img} alt={`${e.username}-mainPic`} />
							{e.username} <FontAwesomeIcon className='online-icon' icon={faCircle} style={{color : e.online === true ? 'green' : 'grey'}} />
								{e.newmess > 0 && <span className='notif-counter'>
										{e.newmess}
									</span>}
									</li>))}
										{chaters.length === 0 && <li>Vous devez matcher pour discuter ;)</li>}
											{error && <li>{error}</li>}
								</ul>
									{chatWindow && chatWindow.map((e, index) => 
										(
											<li key={index} className='chatWindow'>
												<div className='chatWindowHeader' onClick={() => closeWindow(e.id_user)}>
													<img className='chatUserPic' src={e.img} alt={`${e.username}-mainPic`} />
														{e.username}
													<FontAwesomeIcon className='online-icon' icon={faCircle} style={{color : e.online === true ? '#8EC83C' : 'grey'}} />
													<span className="Window-icon" onClick={() => closeWindow(e.id_user)}>&times;</span>

												</div>
												<div className='chatWindowContent'>
													<ul>
															{e.messages && e.messages.map((f, index) =>(
																<li key={index} style={{backgroundColor: f.id_author === state.id_session ? '#8EC83C' : '#D8EED8', marginLeft: f.id_author === state.id_session ? 'auto' : '0px'}}>
																		{f.mess}
																	</li>))}
																</ul>
															</div>
															<form onSubmit={(f) => {sendMessage(f, e)}}>
																<textarea autoFocus placeholder='Ecrivez' value={text[e.id_user]} onChange={(f) => {writeMessage(f, e)}} onKeyDown={(f) => pressEnter(f, e)} />
																<input id={`submit${e.id_user}`} type='submit' value='&rArr;' />
															</form>
														</li>
										))}
													</ul>
											</>
	)
}

//TRANSFORM THE LAST TIME MESSAGE IN DATABASE INTO READABLE STRING
//IS CONDITIONG BY THE DIFFERENCE BETWEEN NOW AND THE LAST TIME
export function getTime(lastTime)
{
	lastTime = new Date(lastTime);
	let nowTime = new Date();
	let diffTime = (nowTime - lastTime) / 3600000;
	diffTime = diffTime < 0 ? -diffTime : diffTime;
	if (diffTime > 24)
		lastTime = lastTime.getDate()+ '/' +(lastTime.getMonth() + 1) + '-' + lastTime.toTimeString().slice(0, 5);
	else
		lastTime = lastTime.toTimeString().slice(0, 5);
	return (lastTime);
}

//CALL THE DB TO GET ALL MESSAGES FROM A CONVERSATION
async function fetchOldMessage(id, myId) {
	try {
		let res = await axios.get(`/user/message/${myId},${id}`);
		if (res.data)
		{
			let lastTime = getTime(res.data[res.data.length - 1].date);
			let messTmp = res.data.map(e => 
				({id_author: e.id_author, mess: e.content}));
			messTmp.push({id_author: -1, mess: lastTime});
			return (messTmp);
		}
		else
			return ([]);
	} catch (err) {
		//console.error(err);
		return ([]);
	}
}
