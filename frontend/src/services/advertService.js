import axios from 'axios';

axios.defaults.baseURL = 'https://jsonplaceholder.typicode.com';
const apiEndpoint = '/posts';

export function getAdverts() {
    _logRequest('get adverts');
    return axios.get(apiEndpoint);
}

export function addAdvert(advert) {
    const url = apiEndpoint;
    const payload = advert;
    _logRequest('add advert', url, payload);
    return axios.post(url, payload);
}

export function updateAdvert(advert) {
    const { id, ...payload } = advert;
    const url = `${apiEndpoint}/${id}`;
    _logRequest('update advert', url, payload);
    return axios.patch(url, payload);
}

export function deleteAdvert(advert) {
    const { id, password } = advert;
    const url = `${apiEndpoint}/${id}`;
    const payload = { password };
    _logRequest('delete advert', url, payload);
    return axios.delete(url, { data: payload });
}

function _logRequest(operation, url = '', payload = '') {
    const requestLogStyle = 'color: orange; font-weight: bold;';
    const requestLog = `%cRequest: ${operation}', url: "%s"${payload && ', payload: '}`;
    console.log(requestLog, requestLogStyle, axios.defaults.baseURL + url, payload);
}
