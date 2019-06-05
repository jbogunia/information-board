#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../class/AdvertRepository.cpp"


// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#bdd-style
TEST_CASE("AdvertRepository", "[repository]")
{
    AdvertRepository advertRepository;

    SECTION("init repository with initial 4 adverts") {
        // when
        int adverts_count = advertRepository.find_all_adverts().size();

        // then
        REQUIRE(adverts_count == 4);
    }

    SECTION("add new advert") {
        // given
        int initial_adverts_count = advertRepository.find_all_adverts().size();
        string new_advert_id = advertRepository.get_new_id();
        Advert *new_advert = new Advert(new_advert_id, "Title", "Body", "Pass");

        // when
        int result = advertRepository.add_advert(new_advert_id, new_advert);
        int adverts_count = advertRepository.find_all_adverts().size();

        // then
        REQUIRE(result == 1);
        REQUIRE(adverts_count == initial_adverts_count + 1);
        REQUIRE(advertRepository.find_advert(new_advert_id) == new_advert);
    }

    SECTION("remove advert") {
        // given
        int initial_adverts_count = advertRepository.find_all_adverts().size();

        // when
        int result = advertRepository.remove_advert("2");
        int adverts_count = advertRepository.find_all_adverts().size();

        // then
        REQUIRE(result == 1);
        REQUIRE(adverts_count == initial_adverts_count - 1);
        REQUIRE(advertRepository.find_advert("2") == nullptr);
    }
}
