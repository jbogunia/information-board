import React from 'react';
import ReactDOM from 'react-dom';
import PropTypes from 'prop-types';


function Modal({ children, open, onClose }) {
    React.useEffect(
        () => {
            if (open) {
                const handleKeyDown = event => {
                    const { key } = event;
                    if (key === 'Escape') onClose();
                };
                window.addEventListener('keydown', handleKeyDown);
                return () => {
                    window.removeEventListener('keydown', handleKeyDown);
                };
            }
        },
        [ open, onClose ],
    );

    return open
        ? ReactDOM.createPortal(
            <div className='modal-background'>
                <div className='modal-container'>
                    <div className='modal'>
                        {children}
                    </div>
                </div>
            </div>,
            document.body,
        )
        : null;
}

Modal.propTypes = {
    children: PropTypes.node.isRequired,
    onClose: PropTypes.func.isRequired,
    open: PropTypes.bool.isRequired,
};

export default Modal;
