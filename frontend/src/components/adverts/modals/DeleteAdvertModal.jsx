import React from 'react';
import Modal from '../../common/Modal';
import AdvertForm from '../../forms/AdvertForm';
import { AppContext } from '../../../context/AppContextProvider';
import { closeDeleteAdvertModal } from '../../../context/actions/closeDeleteAdvertModal';


function DeleteAdvertModal() {
    const { deleteAdvertModalOpen, advertInModal, dispatch } = React.useContext(AppContext);

    const closeModal = React.useCallback(
        () => {
            dispatch(closeDeleteAdvertModal());
        },
        [ dispatch ],
    );

    return (
        <Modal open={deleteAdvertModalOpen} onClose={closeModal}>
            {
                deleteAdvertModalOpen && (
                    <AdvertForm
                        advert={advertInModal}
                        onCancel={closeModal}
                        submitText='Delete'
                        headerText='Delete advert'
                        mode='delete'
                        dispatch={dispatch}
                    />
                )
            }
        </Modal>
    );
}

export default DeleteAdvertModal;
