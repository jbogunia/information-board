#include "catch.hpp"a
#include "../class/Explore.cpp"

TEST_CASE("Explore testing", "explore"){
Explore news("Sprzedam Opla", "5 letni, za 10 zl");
REQUIRE(news.getTitle() == "Sprzedam Opla" );
REQUIRE(news.getText() == "5 letni, za 10 zl");
}