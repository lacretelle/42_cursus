const db = require('../models/user.js');
const check = require("./registration.js");
const fs = require('fs-extra');
const nodemailer = require('nodemailer');
const transporter = nodemailer.createTransport({
	sendmail: true,
	newline: 'unix',
	path: '/usr/sbin/sendmail'
});
const domainMail = require('../config/mail').email;

exports.checkToken = async function(id, token) {
	try {
	let res = await db.checkToken([id, token]);
	return (res);
	} catch (err) {
		//console.error(err);
		return (null);
	}
}

exports.find_withid = async function (req, res) {
	let id = req.params.id;
	let user = await db.find_withid(id);
	let tags = await db.getTags(id);
	if (user)
	{
		let year = user.birthdate.getFullYear();
		let m = user.birthdate.getMonth() + 1;
		m = m.toString().padStart(2, '0');
		let day = user.birthdate.getDate().toString().padStart(2, '0');
		user.age = calculAge(`${year}-${m}-${day}`);
		user.popular = await getPopular(id);
		user.birthdate = `${day}/${m}/${year}`;
		if (!tags)
			tags = [];
		user.tags = tags;
		res.send(user);
	}
	else
		res.send(null);
}

async function getPopular(id) {
	let visited = await db.countVisit(id);
	let liked = await db.countLiked(id);
	let match = await db.countMatchs(id);
	return (visited + (2 * liked) + (3 * match));
}

exports.getNotifs = async function(req, res) {
	let notifs = await db.getNotifs(req.params.id);
	res.send(notifs);
}

exports.getOthersBlocked = async function(req, res) {
	let blocked = await db.getOthersBlocked(req.params.ids.split(','));
	if (blocked)
		res.send(blocked);
	else
		res.send(null);
}


//MATCH
exports.getOthersChat = async function(req, res) {
	let matchs = await db.getOthersChat(req.params.ids.split(','));
	res.send(matchs)
}
exports.getMessages = async function(req, res) {
	let messages = await db.getMessages(req.params.ids.split(','));
	res.send(messages);
}
exports.getInteractions = async function(req, res) {
	let id = req.params.id;
	let visits = await db.getVisitors(id);
	let likes = await db.getLikes(id);
	let matchs = await db.getMatchs(id);
	let blocks = await db.getBlocks(id);
	res.send({visits, likes, matchs, blocks});
}

exports.getOthersInfo = async function(req, res) {
	let id = req.params.id;
	let infos = await db.getUsersInfos(id);
	let imgs = await db.getUsersImgs(id);
	let usersInterests = await db.getUsersInterests(id);
	let pop = await getPopular(id);
	const interest = await require('../models/interest.js').getInterest();
	let finalData = infos.map(e => {
		e.imgs = imgs.filter(f => (f.id_user === e.id_user)).map(i => ({path: i.path, profil: i.profil}));
		e.interest = usersInterests.filter(g => (g.id_user === e.id_user)).map(h=> (h.name_interest));
		e.age = calculAge(e.birthdate);
		e.popular = pop;
		return (e)});
	res.send(finalData);
}

exports.getUserImg = async function (req, res) {
	if (typeof(req.params.id === 'number'))
	{
		let images = await db.getUserImg(req.params.id);
		res.send(images);
	}
	else
		res.send(null);
}

exports.switchProfilImg = async function (req, res) {
	let dbRes = null;
	if (Number.isInteger(req.body.id)
		&& Number.isInteger(req.body.id_img))
		dbRes = await db.setProfilImg([req.body.id, req.body.id_img]);
	res.send(dbRes);
}

exports.deleteUserImg = function (req, res) {
	try {
	db.deleteImg(req.body.id_img);
	fs.unlink(`${__dirname}/../${req.body.path}`);
	res.sendStatus(200);
	} catch (err) {
		//console.error(err);
		res.send(null);
	}
}

function check_sexpref(str)
{
	let error = null;
	if (str !== 'male' && str !== 'female'  && str !== 'bi' && str !== 'other')
		error = '* La préférence est inconnue';
	return ({value : str, error});
}

function check_bio(str)
{
	let error = null;
	if (str.length === 0)
		error =  '* Le champ description est vide.';
	else if (str.length > 160)
		error = '* Votre description est trop longue'
	return ({value : str, error});
}

exports.editInfo = async function (req, res) {
	let sexpref = req.body.sexpref;
	let bio = req.body.bio;
	let id = req.body.id;
	let city = req.body.city;
	let lat = parseFloat(req.body.lat);
	let lon = parseFloat(req.body.lon);
	let check_pref = await check_sexpref(sexpref);
	let checkBio = await check_bio(bio);
	if (checkBio.error === null && check_pref.error === null
		&& city.length > 0 && lat !== 0 && lon !== 0)
	{
		if (await db.insertInfo([sexpref, bio, city, lat, lon, id]))
			res.send('ok');
		else
			res.send('Une erreur est survenue.');
	}
	else
		res.send('Votre profil n\'est pas valide');
}

exports.editCivil = async function (req, res) {
	var data = [];
	let lastname = req.body.lastname;
	let firstname = req.body.firstname;
	let gender = req.body.gender;
	let id = req.body.id;
	let check_gender = await check.check_gender(gender);
	let check_lastname = await check.check_lastname(lastname);
	let check_firstname = await check.check_firstname(firstname);
	if (check_gender.error === null && check_lastname.error === null && check_firstname.error === null) {
		data = [lastname.toUpperCase(), firstname, gender, id];
		await db.insertCivil(data);
		res.send("ok");
	} else {
		res.send("Votre profil n'a pu être mis à jour");
	}
}

exports.editMail = async function (req, res) {
	var data = [];
	let id = req.body.id;
	let mail = req.body.mail;
	let checkMail = await check.check_email(mail);
	if (checkMail.error === null && id !== null) {
		data = [mail, id];
		await db.updateMail(data);
		res.send("ok");
	} else {
		res.send("Votre mail n'a pu être mis à jour.");
	}
}

exports.check_bio = check_bio;

function calculAge(birth)
{
	var test = new Date(birth);
	var diff_ms = Date.now() - test.getTime();
	var age_dt = new Date(diff_ms);
	return(Math.abs(age_dt.getUTCFullYear() - 1970));
}

exports.fakeUser = async function (req, res) {
	let id = req.body.id_other;
	try {
		let result = await db.reportFake(id);
		if (result) {
			sendmailFake(result.firstname, result.mail, result.token);
		}
	} catch (e) {
		console.error(e);
	}
	res.sendStatus(200);
}

exports.blockUser = async function (req, res) {
	let result;
	let id_blocked = req.body.id_blocked;
	let id_author = req.body.id;
	try {
		result = await db.blockUser([id_author, id_blocked]);
	} catch (e) {
		console.error(e);
	}
	res.send({result});
}

exports.deblockUser = async function(req, res) {
	let id_author = req.body.id_author;
	let id_blocked = req.body.id_blocked;
	if (typeof(id_author) === 'number' && typeof(id_blocked) === 'number'
		&& await db.deblockUser([id_author, id_blocked]))
		res.send('OK');
	else
		res.send(null);
}

function sendmailFake(firstname, email, token)
{
	if (email)
	{
		transporter.sendMail({
			from: domainMail,
			to: email,
			subject: 'Votre compte a été reporté comme faux profil',
			text: `Bonjour ${firstname},\n`
			+ "Votre compte a été reporté comme un faux profil.\n"
			+ "Veuillez cliquer ici afin de confirmer votre identité:\n"
			+ `http://localhost:3000/activate/${token}`
			//+ `e1r11p17.42.fr:3001/activate/${token}` 
		}, (err, info) => {
			console.error(err);
		});
	}
}
