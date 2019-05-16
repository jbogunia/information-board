import React from 'react';
import Modal from '../../common/Modal';
import AdvertForm from '../../forms/AdvertForm';
import { AppContext } from '../../../context/AppContextProvider';
import { closeAddAdvertModal } from '../../../context/actions/closeAddAdvertModal';


function AddAdvertModal() {
    const { addAdvertModalOpen, dispatch } = React.useContext(AppContext);

    const closeModal = React.useCallback(
        () => {
            dispatch(closeAddAdvertModal());
        },
        [ dispatch ],
    );

    return (
        <Modal open={addAdvertModalOpen} onClose={closeModal}>
            {
                addAdvertModalOpen && (
                    <AdvertForm
                        onCancel={closeModal}
                        submitText='Add'
                        headerText='Add new advert'
                        mode='add'
                        dispatch={dispatch}
                    />
                )
            }
        </Modal>
    );
}

export default AddAdvertModal;
