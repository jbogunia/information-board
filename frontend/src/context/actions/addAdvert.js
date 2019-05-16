export const ADD_ADVERT = 'adverts:addAdvert';


export function addAdvert(advert) {
    return {
        type: ADD_ADVERT,
        advert: advert,
    };
}
