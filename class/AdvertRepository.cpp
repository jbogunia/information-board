#include <map>
#include <vector>
#include "Advert.cpp"
#include "ErrorMessage.cpp"

using namespace std;


class AdvertRepository {
    int id_generator = -1;
    map<string, Advert*> adverts;

public:
    AdvertRepository() {
        // initialize advert repository with some adverts
        string id = get_new_id();
        adverts[id] = new Advert(id, "Title 0", "Body", "Pass");
        id = get_new_id();
        adverts[id] = new Advert(id, "Title 1", "Body", "Pass");
        id = get_new_id();
        adverts[id] = new Advert(id, "Title 2", "Body", "Pass");
        id = get_new_id();
        adverts[id] = new Advert(id, "Title 3", "Body", "Pass");
    }

    /**
     * Generate new unique advert id
     * @return advert id
     */
    string get_new_id() {
        id_generator++;
        return ::to_string(id_generator);
    }

    /**
     * Save passed advert in memory
     * @param id_advert - unique advert id
     * @param advert - new advert
     * @return
     *      1 -> success
     *      -1 -> id taken
     */
    int add_advert(string id_advert, Advert *advert) {
        if (adverts.count(id_advert) == 0) {
            adverts[id_advert] = advert;
            return 1;
        } else {
            return -1;
        }
    }

    /**
     * Update advert saved under given id
     * @param id_advert - advert id
     * @param new_advert - updated advert
     * @return
     *      1 -> success
     *      -1 -> advert not found, no advert under given id
     *      -2 -> no authorized, when password from new_advert is not equal to saved one
     */
    int update_advert(string id_advert, Advert *new_advert) {
        Advert *advert_to_update = find_advert(id_advert);
        if (advert_to_update != nullptr) {
            if (advert_to_update->getPassword() == new_advert->getPassword()) {
                adverts[id_advert] = new_advert;
                return 1;
            } else {
                return -2;
            }
        } else {
            return -1;
        }
    }

    /**
     * Remove advert saved under given id
     * @param id_advert - advert id
     * @return 1 -> success
     */
    int remove_advert(string id_advert) {
        adverts.erase(id_advert);
        return 1;
    }

    /**
     * Find advert saved under given id
     * @param id_advert - advert id
     * @return saved advert or nullptr when advert is not found
     */
    Advert* find_advert(string id_advert) {
        map<string, Advert*>::iterator it;
        it = adverts.find(id_advert);

        if (it != adverts.end()) {
            return it -> second;
        } else {
            return nullptr;
        }
    }

    /**
     * Find all saved adverts
     * @return vector of saved adverts
     */
    vector<Advert*> find_all_adverts() {
        vector<Advert*> values;
        for (auto const& advert_entry: adverts) {
            values.push_back(advert_entry.second);
        }
        return values;
    }

    // just for develop
    void print_adverts() {
        cout << endl<< "Adverts [" << adverts.size() << "]:" << endl;
        for (auto const& advert_entry: adverts) {
            cout << '\t' << advert_entry.first << " -> " << advert_entry.second->to_json() << endl;
        }
    }
};
