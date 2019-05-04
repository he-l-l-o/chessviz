#include <vector>
using namespace std;

void init(vector<vector<char>>& arr)
{
    arr[0][0] = 'r';
    arr[0][1] = 'n';
    arr[0][2] = 'b';
    arr[0][3] = 'q';
    arr[0][4] = 'k';
    arr[0][5] = 'b';
    arr[0][6] = 'n';
    arr[0][7] = 'r';
    arr[1] = vector<char>(8, 'p');
    arr[7][0] = 'R';
    arr[7][1] = 'N';
    arr[7][2] = 'B';
    arr[7][3] = 'Q';
    arr[7][4] = 'K';
    arr[7][5] = 'B';
    arr[7][6] = 'N';
    arr[7][7] = 'R';
    arr[6] = vector<char>(8, 'P');
}
