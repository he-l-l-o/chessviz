#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void read_console(
        vector< vector< char > >& arr, vector< int >& out, int& color);
int is_upper_case(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return 1;
    }
    return 0;
}
int is_lower_case(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return 1;
    }
    return 0;
}
void error(vector< vector< char > >& arr, vector< int >& out, int& color)
{
    cout << "Неверный ход\n";
    color = 1 - color;
    read_console(arr, out, color);
}

void board_update(vector< vector< char > >& arr, vector< int >& out, int& color)
{
    if (arr[out[1]][out[0]] == 'p') {
        color = 1 - color;
        if (out[2] - out[0] == 0 && out[3] - out[1] == 1
            && arr[out[3]][out[2]] == ' ') {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else if (out[1] == 1 && out[3] == 3 && out[0] == out[2]) {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else if (
                abs(out[2] - out[0]) == 1 && out[3] - out[1] == 1
                && is_upper_case(arr[out[3]][out[2]])) {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else {
            error(arr, out, color);
        }
    }
    if (arr[out[1]][out[0]] == 'P') {
        color = 1 - color;
        if (out[2] - out[0] == 0 && out[3] - out[1] == -1
            && arr[out[3]][out[2]] == ' ') {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else if (out[1] == 6 && out[3] == 4 && out[0] == out[2]) {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else if (
                abs(out[2] - out[0]) == 1 && out[3] - out[1] == -1
                && is_lower_case(arr[out[3]][out[2]])) {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else {
            error(arr, out, color);
        }
    }

    if (arr[out[1]][out[0]] == 'n') {
        color = 1 - color;
        if (abs(out[0] - out[2]) == 2 && abs(out[1] - out[3]) == 1
            && !is_lower_case(arr[out[3]][out[2]])) {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else if (
                abs(out[1] - out[3]) == 2 && abs(out[0] - out[2]) == 1
                && !is_lower_case(arr[out[3]][out[2]])) {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else {
            cout << "Неверный ход\n";
            color = 1 - color;
            read_console(arr, out, color);
        }
    }
    if (arr[out[1]][out[0]] == 'N') {
        color = 1 - color;
        if (abs(out[0] - out[2]) == 2 && abs(out[1] - out[3]) == 1
            && !is_upper_case(arr[out[3]][out[2]])) {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else if (
                abs(out[1] - out[3]) == 2 && abs(out[0] - out[2]) == 1
                && !is_upper_case(arr[out[3]][out[2]])) {
            arr[out[3]][out[2]] = arr[out[1]][out[0]];
            arr[out[1]][out[0]] = ' ';
        } else {
            cout << "Неверный ход\n";
            color = 1 - color;
            read_console(arr, out, color);
        }
    }
}

void read_console(vector< vector< char > >& arr, vector< int >& out, int& color)
{
    setlocale(0, "");
    string in;
    cin >> in;
    if (in == "exit") {
        exit(0);
    }
    if (in[0] >= 'a' && in[0] <= 'h' && in[1] >= '1' && in[1] <= '8'
        && in[3] >= 'a' && in[3] <= 'h' && in[4] >= '1' && in[4] <= '8') {
        out[0] = (int)in[0] - 'a';
        out[1] = (int)in[1] - '0' - 1;
        out[2] = (int)in[3] - 'a';
        out[3] = (int)in[4] - '0' - 1;
        if (color == is_lower_case(arr[out[1]][out[0]])) {
            cout << "Неверный цвет\n";
            read_console(arr, out, color);
            return;
        }
    } else {
        cout << "Неверный ввод\n";
        read_console(arr, out, color);
    }
    board_update(arr, out, color);
}