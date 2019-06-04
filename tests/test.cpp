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
        advertRepository.add_advert(4, "Advert 4");
        REQUIRE(advertRepository.get_adverts_count() == 5);
        REQUIRE(advertRepository.find_advert(4) == "Advert 4");
    }

    SECTION("remove advert with id 4") {
        advertRepository.remove_advert(4);
        REQUIRE(advertRepository.get_adverts_count() == 4);
        REQUIRE(advertRepository.find_advert(4) == "null");
    }
}
