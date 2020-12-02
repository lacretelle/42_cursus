import React, { useContext, useEffect } from 'react'
import { Store } from './store';
import axios from 'axios';
export const SearchStore = React.createContext();

const initialState = {
	cat: '',
	mail: '',
	lastname: '',
	firstname: '',
	bio: '',
	gender: '',
	sexpref: '',
	ageMin: '',
	ageMax: '',
	defaultAge: '',
	birthdate: '',
	localMax: '',
	city: '',
	lat: '',
	lon: '',
	popularMin: '',
	popularMax: '',
	defaultPopular: '',
	defaultTags: [],
	tags: [],
	visits: [],
	likes: [],
	matchs: [],
	blocks: [],
	filter: {}
};

function reducer(state, action) {
	switch (action.type) {
		case 'INIT':
			return (action.payload);
		case 'CHANGE_CIVIL':
			return({...state, lastname: action.lastname,
				firstname: action.firstname, gender: action.gender});
		case 'CHANGE_PUBLIC':
			return({...state, sexpref: action.sexpref, bio: action.bio,
				city: action.city, lat: action.lat, lon: action.lon});
		case 'CHANGE_TAGS':
			return ({...state, defaultTags: action.tags, tags: action.tags});
		case 'CHANGE_MAIL':
			return({...state, mail: action.mail});
		case 'SEARCHSHOW':
			return ({...state, cat: action.cat});
		case 'SEARCHAGE':
			return ({...state, ageMin: action.ageMin, ageMax: action.ageMax});
		case 'SEARCHLOCAL':
			return ({...state, localMax: action.localMax});
		case 'SEARCHPOPULAR':
			return ({...state, popularMin: action.popularMin, popularMax: action.popularMax});
		case 'SEARCHSEXPREF':
			return ({...state, sexpref: action.sexpref});
		case 'SEARCHTAGS':
			return ({...state, tags: action.tags});
		case 'SEARCHFILTER':
			return ({...state, filter: action.filter});
		case 'NEW_VISIT':
			return ({...state, visits: action.payload});
		case 'NEW_LIKE':
			return ({...state, likes: action.payload});
		case 'NEW_UNLIKE':
			return ({...state, likes: action.likes, matchs: action.matchs});
		case 'NEW_MATCH':
			return ({...state, likes: action.likes, matchs: action.matchs});
		case 'NEW_BLOCK':
			return ({...state, blocks: action.payload});
		case 'NEW_GAME':
			return ({...state, visits: action.visits, likes: action.likes});
		default:
			return state;
	}
}

export function SearchProvider(props) {
	const [search, dispatchSearch] = React.useReducer(reducer, initialState);
	const value = { search, dispatchSearch };
	const { state } = useContext(Store);

	useEffect(() => {
		async function fetchUserData() {
			let res = await axios.get(`/user/findWithId/${state.id_session}`);
			let userInfo = res.data;
			res = await axios.get(`/user/interactions/${state.id_session}`);
			let userInteractions = res.data;
			let userVisits = userInteractions.visits;
			let userLikes = userInteractions.likes;
			let userMatchs = userInteractions.matchs;
			let userBlocks = userInteractions.blocks;
			if (userInfo)
			{
				let agemin = userInfo.age - 5 < 18 ? 18 : userInfo.age - 5;
				let agemax = userInfo.age + 5 > 80 ? 80 : userInfo.age + 5;
				let popularMin = userInfo.popular - 15 < 0 ? 0 : userInfo.popular - 15;
				let popularMax = userInfo.popular + 15 > 195 ? 200 : userInfo.popular + 15;
				dispatchSearch({type: 'INIT', payload: {
					cat: 'sugg',
					mail: userInfo.mail,
					lastname: userInfo.lastname,
					firstname: userInfo.firstname,
					bio: userInfo.bio,
					gender: userInfo.gender,
					sexpref: userInfo.sexpref,
					ageMin: agemin,
					ageMax: agemax,
					defaultAge: userInfo.age,
					birthdate: userInfo.birthdate,
					localMax: 10,
					city: userInfo.city,
					lat: userInfo.latitude,
					lon: userInfo.longitude,
					popularMin: popularMin,
					popularMax: popularMax,
					defaultPopular: userInfo.popular,
					defaultTags: userInfo.tags,
					tags: userInfo.tags,
					visits: userVisits,
					likes: userLikes,
					matchs: userMatchs,
					blocks: userBlocks,
					filter: {sex: true, age: false, local: false, popular: false, tags: false, search: {bool: false}}
				}});
			}
		}
		if (state.login)
			fetchUserData();
	}, [state.login, dispatchSearch, state.id_session]);

	return <SearchStore.Provider value={value}>
			{props.children}
		</SearchStore.Provider>
}
