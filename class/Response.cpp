#include <iostream>

using namespace std;


class Response {
private:
    int status; // response status: 200, 401 etc
    string payload; // json payload
public:
    Response(int _status) {
        status = _status;
        payload = "";
    }

    Response(int _status, string _payload) {
        status = _status;
        payload = _payload;
    }

    int getStatus() const {
        return status;
    }

    const string &getPayload() const {
        return payload;
    }
};
