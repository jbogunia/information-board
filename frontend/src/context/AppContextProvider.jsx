import React from 'react';
import PropTypes from 'prop-types';
import { getAdverts } from '../services/advertService';
import { appReducer } from './appReducer';
import { setAdverts } from './actions/setAdverts';


const defaultContext = {
    adverts: [],
    addAdvertModalOpen: false,
    updateAdvertModalOpen: false,
    deleteAdvertModalOpen: false,
    advertInModal: {},
};

export const AppContext = React.createContext(defaultContext);

function AppContextProvider({ children }) {
    const [ state, dispatch ] = React.useReducer(appReducer, defaultContext);

    React.useEffect(
        () => {
            async function fetchData() {
                try {
                    const { data: adverts } = await getAdverts();
                    console.log('%cAdverts successfully fetched.', 'color: green; font-weight: bold;', adverts);
                    dispatch(setAdverts(adverts));
                } catch (e) {
                    alert('Fetching adverts error!');
                    console.error(e);
                }
            }

            fetchData();
        },
        [],
    );

    return (
        <AppContext.Provider value={{
            ...state,
            dispatch,
        }}>
            {children}
        </AppContext.Provider>
    );
}

AppContextProvider.propTypes = {
    children: PropTypes.node.isRequired,
};

export default AppContextProvider;
