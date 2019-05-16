import React from 'react';
import PropTypes from 'prop-types';
import Joi from 'joi-browser';
import ActionContainer from '../common/ActionContainer';
import { withInputData, withInputError, isDataValid, withFormErrors } from './formUtils';
import { addAdvert, deleteAdvert, updateAdvert } from '../../services/advertService';
import { addAdvert as addAdvertAction } from '../../context/actions/addAdvert';
import { updateAdvert as updateAdvertAction } from '../../context/actions/updateAdvert';
import { deleteAdvert as deleteAdvertAction } from '../../context/actions/deleteAdvert';
import TextAreaInput from '../common/TextAreaInput';
import Button from '../common/Button';
import Input from '../common/Input';


const advertFormDataSchema = {
    title: Joi.string().required().min(3).max(128).label('Title'),
    body: Joi.string().required().min(3).max(256).label('Content'),
};

const schemaWithPassword = {
    password: Joi.string().required().min(3).max(64).label('Password'),
};

function getDataSchema(mode) {
    switch (mode) {
        case 'add':
            return advertFormDataSchema;
        case 'modify':
            return ({ ...advertFormDataSchema, ...schemaWithPassword });
        case 'delete':
            return schemaWithPassword;
        default:
            return null;
    }
}

function getInitialData(mode, advert) {
    switch (mode) {
        case 'add':
            return ({
                title: '',
                body: '',
            });
        case 'modify':
            return ({
                title: (advert && advert.title) || '',
                body: (advert && advert.body) || '',
                password: '',
            });
        case 'delete':
            return ({
                password: '',
            });
        default:
            return null;
    }
}


function AdvertForm({ advert, onCancel, submitText, headerText, mode, dispatch }) {
    const [ data, setData ] = React.useState(getInitialData(mode, advert));
    const [ errors, setErrors ] = React.useState({});
    const [ loading, setLoading ] = React.useState(false);

    const dataSchema = React.useMemo(
        () => getDataSchema(mode),
        [ mode ],
    );

    const isValid = React.useMemo(
        () => {
            const dataValid = isDataValid(data, dataSchema);
            const extraErrors = Object.keys(errors).length;
            return dataValid && !extraErrors;
        },
        [ data, errors, dataSchema ],
    );

    const handleChange = React.useCallback(
        ({ currentTarget: input }) => {
            const newData = withInputData(input, data);
            const newErrors = withInputError(input, errors, dataSchema);
            setData(newData);
            setErrors(newErrors);
        },
        [ data, setData, errors, setErrors, dataSchema ],
    );

    const handleSubmit = React.useCallback(
        async event => {
            event.preventDefault();

            async function handleSubmitAddAdvert() {
                let { data: response } = await addAdvert(data);
                console.log('%cAdvert successfully added.', 'color: green; font-weight: bold;', response);
                dispatch(addAdvertAction(response));
            }

            async function handleSubmitUpdateAdvert() {
                let { data: response } = await updateAdvert({
                    id: advert.id,
                    ...data,
                });
                console.log('%cAdvert successfully updated.', 'color: green; font-weight: bold;', response);
                dispatch(updateAdvertAction({ id: advert.id, ...response }));
            }

            async function handleSubmitDeleteAdvert() {
                let { data: response } = await deleteAdvert({
                    id: advert.id,
                    ...data,
                });
                console.log('%cAdvert successfully deleted.', 'color: green; font-weight: bold;', response);
                dispatch(deleteAdvertAction({ id: advert.id, ...response }));
            }

            try {
                // check if data is valid:
                const newErrors = withFormErrors(data, dataSchema);
                if (newErrors) {
                    setErrors(newErrors);
                    return;
                }
                setLoading(true);

                switch (mode) {
                    case 'add':
                        await handleSubmitAddAdvert();
                        break;
                    case 'modify':
                        await handleSubmitUpdateAdvert();
                        break;
                    case 'delete':
                        await handleSubmitDeleteAdvert();
                        break;
                    default:
                        return;
                }
            } catch (e) {
                setLoading(false);
                if (e.response && e.response.status === 401) {
                    console.error('BAD PASSWORD!');
                    setErrors({ password: 'Wrong password!' });
                } else {
                    console.error(e);
                }
            }
        },
        [ data, advert, mode, dispatch, dataSchema ],
    );

    const handleEnterKeyDown = React.useCallback(
        event => {
            const { key } = event;
            if (key === 'Enter') handleSubmit(event);
        },
        [ handleSubmit ],
    );

    const handleCancel = React.useCallback(
        event => {
            event.preventDefault();
            onCancel();
        },
        [ onCancel ],
    );

    return (
        <form className={`advert-form${loading ? ' loading' : ''}`} onSubmit={handleSubmit}>
            <h1>{headerText}</h1>

            {
                (mode !== 'add') && (
                    <Input
                        data={data}
                        errors={errors}
                        name='password'
                        onChange={handleChange}
                        onKeyDown={handleEnterKeyDown}
                        placeholder='Advert password...'
                        type='password'
                        autoFocus={true}
                    />
                )
            }

            {
                (mode !== 'delete') && (
                    <>
                        <Input
                            data={data}
                            errors={errors}
                            name='title'
                            onChange={handleChange}
                            onKeyDown={handleEnterKeyDown}
                            placeholder='Advert title...'
                            autoFocus={mode === 'add'}
                        />

                        <TextAreaInput
                            data={data}
                            errors={errors}
                            name='body'
                            onChange={handleChange}
                            placeholder='Advert content...'
                        />
                    </>
                )
            }

            <ActionContainer>
                <Button onClick={handleCancel} text='Cancel' />
                <Button onClick={handleSubmit} text={submitText} disabled={!isValid} />
            </ActionContainer>
        </form>
    );
}

AdvertForm.propTypes = {
    advert: PropTypes.shape({
        id: PropTypes.oneOfType([ PropTypes.string, PropTypes.number ]).isRequired,
        title: PropTypes.string.isRequired,
        body: PropTypes.string.isRequired,
    }),
    onCancel: PropTypes.func.isRequired,
    submitText: PropTypes.string.isRequired,
    headerText: PropTypes.string.isRequired,
    mode: PropTypes.oneOf([ 'add', 'modify', 'delete' ]).isRequired,
    dispatch: PropTypes.func.isRequired,
};

export default AdvertForm;
