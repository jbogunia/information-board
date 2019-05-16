import React from 'react';
import AdvertForm from '../../forms/AdvertForm';
import Modal from '../../common/Modal';
import { AppContext } from '../../../context/AppContextProvider';
import { closeUpdateAdvertModal } from '../../../context/actions/closeUpdateAdvertModal';


function UpdateAdvertModal() {
    const { updateAdvertModalOpen, advertInModal, dispatch } = React.useContext(AppContext);

    const closeModal = React.useCallback(
        () => {
            dispatch(closeUpdateAdvertModal());
        },
        [ dispatch ],
    );

    return (
        <Modal open={updateAdvertModalOpen} onClose={closeModal}>
            {
                updateAdvertModalOpen && (
                    <AdvertForm
                        advert={advertInModal}
                        onCancel={closeModal}
                        submitText='Modify'
                        headerText='Modify advert'
                        mode='modify'
                        dispatch={dispatch}
                    />
                )
            }
        </Modal>
    );
}

export default UpdateAdvertModal;
