import React from 'react';
import AddAdvertModal from './adverts/modals/AddAdvertModal';
import AppContextProvider from '../context/AppContextProvider';
import Adverts from './adverts/Adverts';
import Header from './navigation/Header';
import UpdateAdvertModal from './adverts/modals/UpdateAdvertModal';
import DeleteAdvertModal from './adverts/modals/DeleteAdvertModal';


function App() {
    return (
        <AppContextProvider>
            <Header />
            <Adverts />

            <AddAdvertModal />
            <UpdateAdvertModal />
            <DeleteAdvertModal />
        </AppContextProvider>
    );
}

export default App;
