#include <map>
#include <vector>
#include "Advert.cpp"

using namespace std;


class AdvertRepository {
    map<string, Advert*> adverts = {
            {"0", new Advert("0", "Title 0", "Body", "Pass")},
            {"1", new Advert("1", "Title 1", "Body", "Pass")},
            {"2", new Advert("2", "Title 2", "Body", "Pass")},
            {"3", new Advert("3", "Title 3", "Body", "Pass")},
    };

public:

    // just for use in tests?
    Advert* find_advert(string id_advert) {
        cout << "Find advert [" << id_advert << "]" << endl;

        map<string, Advert*>::iterator it;
        it = adverts.find(id_advert);

        if (it != adverts.end()) {
            return adverts[id_advert];
        } else {
            cout << "Advert not found!" << endl;
            // place for Null object Pattern?
            return nullptr;
        }
    }

    vector<Advert*> find_all_adverts() {
        vector<Advert*> values;
        for (auto const& advert_entry: adverts) {
            values.push_back(advert_entry.second);
        }
        return values;
    }

    int get_adverts_count() {
        return adverts.size();
    }

    void add_advert(string id_advert, Advert *advert) {
        cout << "Add advert [" << id_advert << ", " << advert->to_string() << "]" << endl;
        if (adverts.count(id_advert) == 0) {
            adverts[id_advert] = advert;
        } else {
            cout << "Advert with given id exists!" << endl;
        }
    }

    void update_advert(string id_advert, Advert *new_advert) {
        cout << "Update advert [" << id_advert << ", " << new_advert << "]" << endl;
        adverts[id_advert] = new_advert;
    }

    void remove_advert(string id_advert) {
        cout << "Remove advert [" << id_advert << "]" << endl;
        adverts.erase(id_advert);
    }


    // just for develop
    void print_adverts() {
        cout << "Adverts [" << adverts.size() << "]:" << endl;
        for (auto const& advert_entry: adverts) {
            cout << '\t' << advert_entry.first << " -> " << advert_entry.second->to_string() << endl;
        }
    }
};
