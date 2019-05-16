export const OPEN_UPDATE_ADVERT_MODAL = 'modal:openUpdateAdvertModal';


export function openUpdateAdvertModal(advert) {
    return {
        type: OPEN_UPDATE_ADVERT_MODAL,
        advert: advert,
    };
}
