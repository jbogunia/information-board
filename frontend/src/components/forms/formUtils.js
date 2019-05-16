import Joi from 'joi-browser';


function validateProperty(input, dataSchema) {
    const { name, value } = input;
    const obj = { [ name ]: value };
    const schema = { [ name ]: dataSchema[ name ] };
    const { error } = Joi.validate(obj, schema);
    return error ? error.details[ 0 ].message : null;
}

export function isDataValid(data, dataSchema) {
    const { error } = Joi.validate(data, dataSchema, { abortEarly: false });
    return !Boolean(error);
}

export function withInputData(input, data) {
    const { name, value } = input;
    const newData = { ...data };
    newData[ name ] = value;
    return newData;
}

export function withInputError(input, errors, dataSchema) {
    const newErrors = { ...errors };
    const errorMessage = validateProperty(input, dataSchema);
    if (errorMessage) {
        newErrors[ input.name ] = errorMessage;
    } else {
        delete newErrors[ input.name ];
    }
    return newErrors;
}

export function withFormErrors(data, dataSchema) {
    const { error } = Joi.validate(data, dataSchema, { abortEarly: false });
    if (!error) return null;
    const newErrors = {};
    for (let item of error.details) newErrors[ item.path[ 0 ] ] = item.message;
    return newErrors;
}
