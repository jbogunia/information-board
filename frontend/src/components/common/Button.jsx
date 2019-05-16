import React from 'react';
import PropTypes from 'prop-types';


function Button({ disabled, onClick, text }) {
    return (
        <button className='btn' disabled={disabled} onClick={onClick}>
            {text}
        </button>
    );
}

Button.propTypes = {
    disabled: PropTypes.bool,
    onClick: PropTypes.func.isRequired,
    text: PropTypes.string.isRequired,
};

export default Button;
