#include <iostream>
#include <map>
#include "../Repository.cpp"


// instance of repository
Repository repository;

void errors_handling() {
    // create new error message object
    ErrorMessage *error = new ErrorMessage("password", "Wrong password!");

    cout << endl<< "Error message:" << endl;
    cout << error->to_json() << endl;
}

void adverts_to_json() {
    // map list of adverts from repository to json format
    string adverts_json = "[";
    for (auto const &advert: repository.find_all()) {
        adverts_json += advert->to_json() + ",";
    }
    adverts_json.replace(adverts_json.length() - 1, 1, "]");

    cout << endl<< "Adverts JSON:" << endl;
    cout << adverts_json << endl;
}

int main() {
    errors_handling();
    adverts_to_json();

    repository.print_adverts();

    // add advert:
    string new_advert_id = repository.get_new_id();
    Advert *new_advert = new Advert(new_advert_id, "Title", "Body", "Pass");
    cout << endl<< "Add advert: " << new_advert->to_json() << endl;
    int add_result = repository.add(new_advert_id, new_advert);
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
    repository.print_adverts();

    // update advert:
    string update_advert_id = new_advert_id;
    Advert *updated_advert = new Advert(update_advert_id, "Updated title", "Body", "Pass");
    cout << endl<< "Update advert: " << updated_advert->to_json() << endl;
    int update_result = repository.update(update_advert_id, updated_advert);
    switch (update_result) {
        case 1: {
            cout << "Advert updated successfully" << endl;
            break;
        }
        case -1: {
            cout << "No advert with given id found" << endl;
            break;
        }
        case -2: {
            cout << "No authorized!" << endl;
//            ErrorMessage *error = new ErrorMessage("password", "Wrong password!");
            break;
        }
    }
    repository.print_adverts();

    // remove advert
    cout << endl << "Remove advert: " + new_advert_id << endl;
    int remove_result = repository.remove(new_advert_id, "Pass");
    switch (remove_result) {
        case 1: {
            cout << "Advert removed successfully" << endl;
            break;
        }
        case -1: {
            cout << "No advert with given id found" << endl;
            break;
        }
        case -2: {
            cout << "No authorized!" << endl;
//            ErrorMessage *error = new ErrorMessage("password", "Wrong password!");
            break;
        }
    }
    repository.print_adverts();
}
