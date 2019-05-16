import React from 'react';
import PropTypes from 'prop-types';
import ActionContainer from '../common/ActionContainer';
import Button from '../common/Button';
import { openUpdateAdvertModal } from '../../context/actions/openUpdateAdvertModal';
import { openDeleteAdvertModal } from '../../context/actions/openDeleteAdvertModal';


function Advert({ advert, dispatch }) {
    const [ expanded, setExpanded ] = React.useState(false);

    const handleToggleAdvert = React.useCallback(
        () => {
            setExpanded(prevExpanded => !prevExpanded);
        },
        [ setExpanded ],
    );

    const handleDeleteButtonClick = React.useCallback(
        e => {
            e.stopPropagation();
            dispatch(openDeleteAdvertModal(advert));
        },
        [ dispatch, advert ],
    );

    const handleModifyButtonClick = React.useCallback(
        e => {
            e.stopPropagation();
            dispatch(openUpdateAdvertModal(advert));
        },
        [ dispatch, advert ],
    );

    return (
        <>
            <div className={`advert${expanded ? ' expanded' : ''}`} onClick={handleToggleAdvert}>
                <div className='advert-header'>{advert.title}</div>
                <div className='advert-body'>
                    {
                        advert.body.split('\n').map((line, index) => <p key={index}>{line}</p>)
                    }
                </div>

                {
                    expanded && (
                        <ActionContainer>
                            <Button text='Delete' onClick={handleDeleteButtonClick} />
                            <Button text='Modify' onClick={handleModifyButtonClick} />
                        </ActionContainer>
                    )
                }
            </div>
        </>
    );
}

Advert.propTypes = {
    advert: PropTypes.object.isRequired,
    dispatch: PropTypes.func.isRequired,
};

export default React.memo(Advert);
