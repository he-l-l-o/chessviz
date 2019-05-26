#include "../src/board_read.h"
#include "../src/board_start.h"
#define CATCH_CONFIG_MAIN
#include "../thirdparty/Catch/catch.hpp"
TEST_CASE("Board initialization")
{
    vector< vector< char > > arr(8, vector< char >(8, ' '));
    init(arr);
    REQUIRE(arr[2][2] == ' ');
    REQUIRE(arr[0][0] == 'r');
    REQUIRE(arr[1][1] == 'p');
}
TEST_CASE("Additional functions")
{
    REQUIRE(is_lower_case('a') == 1);
    REQUIRE(is_lower_case('A') == 0);
    REQUIRE(is_upper_case('a') == 0);
    REQUIRE(is_upper_case('A') == 1);
}
TEST_CASE("Board update function")
{
    vector< vector< char > > arr(8, vector< char >(8, ' '));
    init(arr);
    vector< int > out(4, 0);
    out[0] = 1;
    out[1] = 1;
    out[2] = 1;
    out[3] = 3;
    int color = 0;
    board_update(arr, out, color);
    REQUIRE(arr[3][1] == 'p');
    out[0] = 0;
    out[1] = 1;
    out[2] = 0;
    out[3] = 2;
    board_update(arr, out, color);
    REQUIRE(arr[2][0] == 'p');
    out[0] = 1;
    out[1] = 0;
    out[2] = 2;
    out[3] = 2;
    board_update(arr, out, color);
    REQUIRE(arr[2][2] == 'n');
}