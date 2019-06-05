#include "Repository.cpp"
#include "Response.cpp"


Repository repository;

class Controller {
public:

    /**
     * Get saved adverts
     * @return response object with advert list payload
     */
    Response *get_adverts() {
        string adverts_json = "[";
        for (auto const &advert: advertRepository.find_all_adverts()) {
            adverts_json += advert->to_json() + ",";
        }
        adverts_json.replace(adverts_json.length() - 1, 1, "]");

        return new Response(200, adverts_json);
    }

    /**
     * Save advert
     * @param title - advert title
     * @param body - advert body
     * @param password - advert password
     * @return response object with added advert or error message
     */
    Response *add_advert(string title, string body, string password) {
        // validate data
        // get advert id
        // create new Advert obj
        // add/save advert
        // handle result
        // get saved advert
        Advert *saved_advert = nullptr;

        // return response
        return new Response(200, saved_advert->to_json());
    }

    /**
     * Update advert
     * @param id - advert id
     * @param title - updated advert title
     * @param body - updated advert body
     * @param password - advert password, must match already saved one
     * @return response object with updated advert or error message
     */
    Response *update_advert(string id, string title, string body, string password) {
        // validate data
        // create new Advert obj
        // update advert
        // handle result
        // get updated advert
        Advert *updated_advert = nullptr;

        // return response
        return new Response(200, updated_advert->to_json());
    }


    /**
     * Remove advert
     * @param id - advert id
     * @param password - advert password, must match already saved one
     * @return response object with updated advert or error message
     */
    Response *delete_advert(string id, string password) {
        // remove advert
        // handele result

        // return response
//        return new Response(200);

        // eg when errors
        ErrorMessage *error = new ErrorMessage("password", "Wrong password!");
        return new Response(401, error->to_json());
    }

};