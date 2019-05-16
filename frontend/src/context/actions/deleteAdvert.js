export const DELETE_ADVERT = 'adverts:deleteAdvert';


export function deleteAdvert(advert) {
    return {
        type: DELETE_ADVERT,
        advert: advert,
    };
}
