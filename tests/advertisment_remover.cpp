#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../class/advertisment_remover.cpp"
#include "catch.hpp"


/* delete_advertisment execution codes:
    0 - advertisment existed and was deleted succesfully
    1 - advertisment existed and was not deleted succesfully
    2 - advertisment with this ID not existed
    3 - advertisment

*/


TEST_CASE("Test: succesfull removing advertisment", "[classic]")
{
    SECTION("Test first IB - Information board - 1 to 1000th advertisments"){
        for (int i = 1; i < 1000; i += 1)
        REQUIRE(delete_advertisment(i) == 0);
    }
}

TEST_CASE("Test: Not succesfull removing advertisment", "[classic]")
{
    SECTION("Test first IB - Information board - 1 to 1000th advertisments"){
        for (int i = 1; i < 1000; i += 1)
        REQUIRE(delete_advertisment(i) == 1);
    }
}

TEST_CASE("Test:  Advertisment with this ID not existed", "[classic]")
{
    SECTION("Test first IB - Information board - 1 to 1000th advertisments"){
        for (int i = 1; i < 1000; i += 1)
        REQUIRE(delete_advertisment(i) == 2);
    }
}
