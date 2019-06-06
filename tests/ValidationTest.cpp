#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../class/Validation.cpp"

TEST_CASE( "ValidationTest", "[validation]" ) {
    SECTION("test title") {

        // too long title
        REQUIRE(!Validation::validateTitle((char*)"Too long title"));

        //good length
        REQUIRE(Validation::validateTitle((char*)"Title"));

        //more then 3 char, that are no letters (possibility of spam)
        REQUIRE(!Validation::validateTitle((char*)"SPAM!!!!!"));
    }
    SECTION("test body"){
        //no body test
        REQUIRE(!Validation::validateBody((char*)""));

        //too long text in the body
        REQUIRE(!Validation::validateBody((char*)"This is really long text in the body, can be spam."));

        //good length
        REQUIRE(Validation::validateBody((char*)"This is fine."));

    }


    SECTION("test password"){
        //too short password
        REQUIRE(!Validation::validatePassword((char*)"sh1"));

        //too long password
        REQUIRE(!Validation::validatePassword((char*)"Toolongpassowrd1"));

        //no digit in password
        REQUIRE(!Validation::validatePassword((char*)"nodigit"));

        //good password
        REQUIRE(Validation::validatePassword((char*)"goodpass1"));

    }
}
