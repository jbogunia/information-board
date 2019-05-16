import axios from 'axios';

axios.defaults.baseURL = 'https://192.168.1.1';
const apiEndpoint = '/posts';

export function getAdverts() {
    logRequest('get adverts');
    return axios.get(apiEndpoint);
}

export function addAdvert(advert) {
    const url = apiEndpoint;
    const payload = advert;
    logRequest('add advert', url, payload);
    return axios.post(url, payload);
}

export function updateAdvert(advert) {
    const { id, ...payload } = advert;
    const url = `${apiEndpoint}/${id}`;
    logRequest('update advert', url, payload);
    return axios.patch(url, payload);
}

export function deleteAdvert(advert) {
    const { id, password } = advert;
    const url = `${apiEndpoint}/${id}`;
    const payload = { password };
    logRequest('delete advert', url, payload);
    return axios.delete(url, { data: payload });
}

function logRequest(operation, url = '', payload = '') {
    const requestLogStyle = 'color: orange; font-weight: bold;';
    const requestLog = `%cRequest: ${operation}', url: "%s"${payload && ', payload: '}`;
    console.log(requestLog, requestLogStyle, axios.defaults.baseURL + url, payload);
}
