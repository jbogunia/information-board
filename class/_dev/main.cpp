#include <iostream>
#include <map>
#include "../AdvertRepository.cpp"


// instance of advertRepository
AdvertRepository advertRepository;

void errors_handling() {
    // create new error message object
    ErrorMessage *error = new ErrorMessage("password", "Wrong password!");

    cout << endl<< "Error message:" << endl;
    cout << error->to_json() << endl;
}

void adverts_to_json() {
    // map list of adverts from advertRepository to json format
    string adverts_json = "[";
    for (auto const &advert: advertRepository.find_all_adverts()) {
        adverts_json += advert->to_json() + ",";
    }
    adverts_json.replace(adverts_json.length() - 1, 1, "]");

    cout << endl<< "Adverts JSON:" << endl;
    cout << adverts_json << endl;
}

int main() {
    errors_handling();
    adverts_to_json();

    advertRepository.print_adverts();

    // add advert:
    string new_advert_id = advertRepository.get_new_id();
    Advert *new_advert = new Advert(new_advert_id, "Title", "Body", "Pass");
    cout << endl<< "Add advert: " << new_advert->to_json() << endl;
    int add_result = advertRepository.add_advert(new_advert_id, new_advert);
    switch (add_result) {
        case 1: {
            cout << "Advert added successfully" << endl;
            break;
        }
        case -1: {
            cout << "Advert with given id exists!" << endl;
            break;
        }
    }
    advertRepository.print_adverts();

    // update advert:
    string update_advert_id = new_advert_id;
    Advert *updated_advert = new Advert(update_advert_id, "Updated title", "Body", "Pass");
    cout << endl<< "Update advert: " << updated_advert->to_json() << endl;
    int update_result = advertRepository.update_advert(update_advert_id, updated_advert);
    switch (update_result) {
        case 1: {
            cout << "Advert updated successfully" << endl;
            break;
        }
        case -1: {
            cout << "No advert with given found" << endl;
            break;
        }
        case -2: {
            cout << "No authorized!" << endl;
//            ErrorMessage *error = new ErrorMessage("password", "Wrong password!");
            break;
        }
    }
    advertRepository.print_adverts();

    // remove advert
    cout << endl << "Remove advert: " + new_advert_id << endl;
    int remove_result = advertRepository.remove_advert(new_advert_id);
    switch (remove_result) {
        case 1: {
            cout << "Advert removed successfully" << endl;
            break;
        }
    }
    advertRepository.print_adverts();
}
