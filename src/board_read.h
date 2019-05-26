#pragma once
#include <iostream>
#include <vector>
using namespace std;

void read_console(
        vector< vector< char > >& arr, vector< int >& out, int& color);
int is_upper_case(char ch);
int is_lower_case(char ch);
void board_update(
        vector< vector< char > >& arr, vector< int >& out, int& color);
