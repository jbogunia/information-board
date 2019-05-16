import React from 'react';
import { AppContext } from '../../context/AppContextProvider';
import { openAddAdvertModal } from '../../context/actions/openAddAdvertModal';


function Header() {
    const { dispatch } = React.useContext(AppContext);

    function openAddAdvert() {
        dispatch(openAddAdvertModal());
    }

    return (
        <header>
            <span className='logo'>Information board</span>
            <span className='nav-clickable' onClick={openAddAdvert}>New advert</span>
        </header>
    );
}

export default Header;
