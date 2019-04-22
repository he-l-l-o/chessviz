#include "board_print_plain.h"
#include "board_read.h"
#include "board_start.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<vector<char>> arr(8, vector<char>(8, ' '));
  init(arr);
  out(arr);
}