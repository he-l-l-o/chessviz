#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void read_console(vector<vector<char>> &arr) {
  setlocale(0, "");
  string in;
  char t;
  int x1, x2, y1, y2;
  cin >> in;
  if (in == "exit") {
    exit(0);
  }
  if (in[0] >= 'a' && in[0] <= 'h' && in[1] >= '1' && in[1] <= '8' &&
      in[3] >= 'a' && in[3] <= 'h' && in[4] >= '1' && in[4] <= '8') {
    x1 = (int)in[0] - 'a';
    y1 = (int)in[1] - '0' - 1;
    x2 = (int)in[3] - 'a';
    y2 = (int)in[4] - '0' - 1;
    // if (arr[y1][x1] == 'p')
    // arr[y2][x2] = arr[y1][x1];
  } else {
    cout << "Неверный ввод\n";
    read_console(arr);
  }
  if (arr[y1][x1] == 'p') {
    if (x2 - x1 == 0 && y2 - y1 == 1 && arr[y2][x2] == ' ') {
      arr[y2][x2] = arr[y1][x1];
      arr[y1][x1] = ' ';
    } else if (y1 == 1 && y2 == 3 && x1 == x2) {
      arr[y2][x2] = arr[y1][x1];
      arr[y1][x1] = ' ';
    } else if (abs(x2 - x1) == 1 && y2 - y1 == 1 && arr[y2][x2] != ' ') {
      arr[y2][x2] = arr[y1][x1];
      arr[y1][x1] = ' ';
    } else {
      cout << "Неверный ход\n";
      read_console(arr);
    }
  }
  if (arr[y1][x1] == 'P') {
    if (x2 - x1 == 0 && y2 - y1 == -1 && arr[y2][x2] == ' ') {
      arr[y2][x2] = arr[y1][x1];
      arr[y1][x1] = ' ';
    } else if (y1 == 6 && y2 == 4 && x1 == x2) {
      arr[y2][x2] = arr[y1][x1];
      arr[y1][x1] = ' ';
    } else if (abs(x2 - x1) == 1 && y2 - y1 == -1 && arr[y2][x2] != ' ') {
      arr[y2][x2] = arr[y1][x1];
      arr[y1][x1] = ' ';
    } else {
      cout << "Неверный ход\n";
      read_console(arr);
    }
  }
}