import React from 'react';
import PropTypes from 'prop-types';


function Input({data, errors, name, ...rest}) {
    const value = data[name];
    const error = errors[name];

    return (
        <div className='input-wrapper'>
            <input
                className={`input${error ? ' with-error' : ''}`}
                id={name}
                name={name}
                value={value}
                {...rest}
            />
            {error && <div className='input-error'>{error}</div>}
        </div>
    );
}

Input.propTypes = {
    data: PropTypes.object.isRequired,
    errors: PropTypes.object.isRequired,
    name: PropTypes.string.isRequired,
    onChange: PropTypes.func.isRequired,
    placeholder: PropTypes.string.isRequired,
    type: PropTypes.string,
    autoFocus: PropTypes.bool,
};

export default Input;
