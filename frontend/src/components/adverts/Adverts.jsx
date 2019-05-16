import React from 'react';
import { AppContext } from '../../context/AppContextProvider';
import Advert from './Advert';


function Adverts() {
    const { adverts, dispatch } = React.useContext(AppContext);
    return (
        <main className='advert-list'>
            {
                adverts.map(advert => <Advert key={advert.id} advert={advert} dispatch={dispatch} />)
            }
        </main>
    );
}

export default Adverts;
