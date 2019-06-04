#include <iostream>
#include <map>
#include <vector>


class AdvertRepository {
    std::map<int, std::string> adverts = {
            {0, "Advert 0"},
            {1, "Advert 1"},
            {2, "Advert 2"},
            {3, "Advert 3"},
    };

public:
    std::string find_advert(int id_advert) {
        std::cout << "Find advert [" << id_advert << "]" << std::endl;

        std::map<int, std::string>::iterator it;
        it = adverts.find(id_advert);
        if (it != adverts.end()) {
            return adverts[id_advert];
        } else {
            std::cout << "Advert not found!" << std::endl;
            // place for Null object Pattern?
            return "null";
        }
    }

    std::vector<std::string> find_all_adverts() {
        std::vector<std::string> values(adverts.size());
        for (const auto& it : adverts) {
            values.push_back(it.second);
        }
        return values;
    }

    int get_adverts_count() {
        return adverts.size();
    }

    void add_advert(int id_advert, std::string advert) {
        std::cout << "Add advert [" << id_advert << ", " << advert << "]" << std::endl;
        if (adverts.count(id_advert) == 0) {
            adverts[id_advert] = advert;
        } else {
            std::cout << "Advert with given id exists!" << std::endl;
        }
    }

    void update_advert(int id_advert, std::string new_advert) {
        std::cout << "Update advert [" << id_advert << ", " << new_advert << "]" << std::endl;
        adverts[id_advert] = new_advert;
    }

    void remove_advert(int id_advert) {
        std::cout << "Remove advert [" << id_advert << "]" << std::endl;
        adverts.erase(id_advert);
    }

    void print_adverts() {
        std::cout << "Adverts [" << adverts.size() << "]:" << std::endl;
        for (const auto& it : adverts) {
            std::cout << '\t' << it.first << " -> " << it.second << std::endl;
        }
    }
};
