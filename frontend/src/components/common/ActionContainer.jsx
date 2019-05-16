import React from 'react';
import PropTypes from 'prop-types';


function ActionContainer({ children }) {
    return (
        <div className='action-container'>
            {children}
        </div>
    );
}

ActionContainer.propTypes = {
    children: PropTypes.node.isRequired,
};

export default ActionContainer;
