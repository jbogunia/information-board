export const OPEN_DELETE_ADVERT_MODAL = 'modal:openDeleteAdvertModal';


export function openDeleteAdvertModal(advert) {
    return {
        type: OPEN_DELETE_ADVERT_MODAL,
        advert: advert,
    };
}
