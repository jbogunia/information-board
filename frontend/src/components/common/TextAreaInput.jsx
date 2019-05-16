import React from 'react';
import PropTypes from 'prop-types';


function TextAreaInput({ data, errors, name, ...rest }) {
    const value = data[ name ];
    const error = errors[ name ];
    const rows = value.split('\n').length;

    return (
        <div className='input-wrapper'>
            <textarea
                className={`input${error ? ' with-error' : ''}`}
                id={name}
                name={name}
                value={value}
                rows={rows}
                {...rest}
            />
            {error && <div className='input-error'>{error}</div>}
        </div>
    );
}

TextAreaInput.propTypes = {
    data: PropTypes.object.isRequired,
    errors: PropTypes.object.isRequired,
    name: PropTypes.string.isRequired,
    onChange: PropTypes.func.isRequired,
    placeholder: PropTypes.string.isRequired,
    type: PropTypes.string,
};

export default TextAreaInput;
