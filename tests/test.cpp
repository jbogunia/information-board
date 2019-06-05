#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../class/Repository.cpp"


// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#bdd-style
TEST_CASE("repository", "[repository]")
{
    Repository repository;

    SECTION("init repository with initial 4 adverts") {
        // when
        int adverts_count = repository.find_all().size();

        // then
        REQUIRE(adverts_count == 4);
    }

    SECTION("add new advert") {
        // given
        int initial_adverts_count = repository.find_all().size();
        string new_advert_id = repository.get_new_id();
        Advert *new_advert = new Advert(new_advert_id, "Title", "Body", "Pass");

        // when
        int result = repository.add(new_advert_id, new_advert);
        int adverts_count = repository.find_all().size();

        // then
        REQUIRE(result == 1);
        REQUIRE(adverts_count == initial_adverts_count + 1);
        REQUIRE(repository.find_by_id(new_advert_id) == new_advert);
    }

    SECTION("remove advert") {
        // given
        int initial_adverts_count = repository.find_all().size();

        // when
        int result = repository.remove("2", "Pass");
        int adverts_count = repository.find_all().size();

        // then
        REQUIRE(result == 1);
        REQUIRE(adverts_count == initial_adverts_count - 1);
        REQUIRE(repository.find_by_id("2") == nullptr);
    }
}
