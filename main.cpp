#include <iostream>
#include <vector>
using namespace std;

void out(vector<vector<char>>& arr)
{
    for (unsigned i = 0; i < arr.size(); i++) {
        // cout << "----------------\n";
        for (unsigned j = 0; j < arr[0].size(); j++) {
            cout << "|";
            if (arr[i][j] != ' ') {
                cout << arr[i][j];
            } else if ((i + j) % 2 == 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "|\n";
    }
    // cout << "----------------\n";
}
int main()
{
    vector<vector<char>> arr(8, vector<char>(8, ' '));
    out(arr);
}