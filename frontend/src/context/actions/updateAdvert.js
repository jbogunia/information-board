export const UPDATE_ADVERT = 'adverts:updateAdvert';


export function updateAdvert(advert) {
    return {
        type: UPDATE_ADVERT,
        advert: advert,
    };
}
