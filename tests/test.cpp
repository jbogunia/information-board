#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../class/AdvertRepository.cpp"


// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#bdd-style
TEST_CASE("AdvertRepository", "[repository]")
{
    AdvertRepository advertRepository;

    SECTION("init repository with initial 4 adverts") {
        REQUIRE(advertRepository.get_adverts_count() == 4);
    }

    SECTION("add new advert with id 4") {
        advertRepository.add_advert("4", new Advert("5", "Title", "Body", "Pass"));
        REQUIRE(advertRepository.get_adverts_count() == 5);
    }

    SECTION("remove advert with id 4") {
        advertRepository.remove_advert("4");
        REQUIRE(advertRepository.get_adverts_count() == 4);
        REQUIRE(advertRepository.find_advert("4") == nullptr);
    }
}

//advertRepository.print_adverts();
//
//cout << "count:" << advertRepository.get_adverts_count() << endl;
//
//Advert *a = advertRepository.find_advert("1");
//cout << "'" << a->to_string() << "'" << endl;
//
//advertRepository.add_advert("5", new Advert("5", "Title", "Body", "Pass"));
//advertRepository.print_adverts();
//
//advertRepository.remove_advert("5");
//advertRepository.print_adverts();

//// prepare json adverts array:
//string adverts_json = "[";
//for(auto const& advert: advertRepository.find_all_adverts()) {
//adverts_json += advert->to_json() + ",";
//}
//adverts_json.replace(adverts_json.length() - 1, 1, "]");
//cout << adverts_json << endl;
