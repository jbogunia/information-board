#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "OpenFileFail", "open file fail, wrong path" ) {
std::fstream fileStream;
fileStream.open("..\\adverts.json");
if (fileStream.fail()) {
std::cout << "FileStream Open Fail"<< std::endl;
}
fileStream.close();
bool is_fail = fileStream.fail();
REQUIRE_FALSE(!is_fail );
}

TEST_CASE( "OpenFilePass", "open file pass" ) {
std::fstream fileStream;
fileStream.open("..\\data\\adverts.json");
if (fileStream.fail()) {
std::cout << "FileStream Open Fail"<< std::endl;
}
fileStream.close();
REQUIRE_FALSE(fileStream.fail() );
}

TEST_CASE( "CloseFileTrue", "file is close" ) {
std::fstream fileStream;
fileStream.open("..\\data\\adverts.json");
if (fileStream.fail()) {
std::cout << "FileStream Open Fail"<< std::endl;
}
fileStream.close();
REQUIRE_FALSE(fileStream.is_open());
}

TEST_CASE( "CloseFileFalse", "file is not close" ) {
std::fstream fileStream;
fileStream.open("..\\data\\adverts.json");
if (fileStream.fail()) {
std::cout << "FileStream Open Fail"<< std::endl;
}
bool is_open = fileStream.is_open();
REQUIRE_FALSE(!is_open);
}

