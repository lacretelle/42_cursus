import React, { useEffect, useContext, useState } from 'react';
import Header from '../components/header';
import { Store } from '../store';
import Gallery from '../components/match/gallery';
import axios from 'axios';
import '../css/match.css';
import '../css/home.css';

export default function Home(props) {
	const { state }  = useContext(Store);
	const [others, setOthers] = useState([]);

	useEffect(() => {
		async function fetchOthersData() {
			let res = await axios.get(`/user/others/${state.id_session}`);
			if (res.data)
				setOthers(res.data);
		}
		if (state.login)
			fetchOthersData();
	}, [state.login, state.id_session]);

	if (state.login)
		return (
			<>
<Header />
	<Gallery others={others} state={state} />
	</>
		);
	else
		return (
			<>
	<Header />
	<section className="homeLogout">
		<div>
			<p>Trouve ta moitié - MATCHA -</p>
		</div>
	</section>
			</>
		);
}
