#include <iostream>

using namespace std;

class ErrorMessage {
private:
    string field; // "title" or "body" or "password"
    string message;
public:
    ErrorMessage(string _field, string _message) {
        field = _field;
        message = _message;
    }

    string to_json() {
        return "{\"field\":\"" + field + "\",\"message\":\"" + message + "\"}";
    };
};
