import { SET_ADVERTS } from './actions/setAdverts';
import { ADD_ADVERT } from './actions/addAdvert';
import { UPDATE_ADVERT } from './actions/updateAdvert';
import { DELETE_ADVERT } from './actions/deleteAdvert';
import { OPEN_ADD_ADVERT_MODAL } from './actions/openAddAdvertModal';
import { OPEN_UPDATE_ADVERT_MODAL } from './actions/openUpdateAdvertModal';
import { OPEN_DELETE_ADVERT_MODAL } from './actions/openDeleteAdvertModal';
import { CLOSE_ADD_ADVERT_MODAL } from './actions/closeAddAdvertModal';
import { CLOSE_UPDATE_ADVERT_MODAL } from './actions/closeUpdateAdvertModal';
import { CLOSE_DELETE_ADVERT_MODAL } from './actions/closeDeleteAdvertModal';


export function appReducer(state, action) {
    console.debug('appReducer', { state, action });

    switch (action.type) {
        case SET_ADVERTS:
            return {
                ...state,
                adverts: action.adverts.sort((a, b) => b.id - a.id),
            };

        case ADD_ADVERT:
            return {
                ...state,
                adverts: [ action.advert, ...state.adverts ],
                addAdvertModalOpen: false,
            };

        case UPDATE_ADVERT:
            const adverts = [ ...state.adverts ];
            adverts[ adverts.findIndex(a => a.id === action.advert.id) ] = action.advert;
            return {
                ...state,
                adverts: adverts,
                updateAdvertModalOpen: false,
            };

        case DELETE_ADVERT:
            return {
                ...state,
                adverts: state.adverts.filter(a => a.id !== action.advert.id),
                deleteAdvertModalOpen: false,
            };

        case OPEN_ADD_ADVERT_MODAL:
            return {
                ...state,
                addAdvertModalOpen: true,
            };
        case CLOSE_ADD_ADVERT_MODAL:
            return {
                ...state,
                addAdvertModalOpen: false,
            };

        case OPEN_UPDATE_ADVERT_MODAL:
            return {
                ...state,
                updateAdvertModalOpen: true,
                advertInModal: action.advert,
            };
        case CLOSE_UPDATE_ADVERT_MODAL:
            return {
                ...state,
                updateAdvertModalOpen: false,
            };

        case OPEN_DELETE_ADVERT_MODAL:
            return {
                ...state,
                deleteAdvertModalOpen: true,
                advertInModal: action.advert,
            };
        case CLOSE_DELETE_ADVERT_MODAL:
            return {
                ...state,
                deleteAdvertModalOpen: false,
            };

        default:
            return state;
    }
}
