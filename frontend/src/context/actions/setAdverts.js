export const SET_ADVERTS = 'adverts:setAdverts';


export function setAdverts(adverts) {
    return {
        type: SET_ADVERTS,
        adverts: adverts,
    };
}
