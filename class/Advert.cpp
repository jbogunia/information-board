#include <iostream>

using namespace std;

class Advert {
private:
    string id;
    string title;
    string body;
    string password;
public:
    Advert(string _id, string _title, string _body, string _password) {
        id = _id;
        title = _title;
        body = _body;
        password = _password;
    };

    string to_json() {
//        return "{\"id\":\"" + id + "\",\"title\":\"" + title + "\",\"body\":\"" + body + "\"}";
        return "{\"id\":\"" + id + "\",\"title\":\"" + title + "\",\"body\":\"" + body + "\",\"password:\"" + password + "\"}";
    };

    const string &getPassword() const {
        return password;
    }
};
