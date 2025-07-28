#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
vector<int> v;
int N, M, T;
bool xf, of;
void check(vector<vector<char>> board) {
    xf = false;
    of = false;
    if ((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && (board[2][0] != '.')) {
        if (board[2][0] == 'X') xf = true;
        else of = true;
    }
    if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) && (board[2][1] != '.')){
        if (board[2][1] == 'X') xf = true;
        else of = true;
}
    if ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && (board[2][2] != '.')){
        if (board[2][2] == 'X') xf = true;
        else of = true;
    }
    if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) && (board[0][2] != '.')){
        if (board[0][2] == 'X') xf = true;
        else of = true;
    }
    if ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && (board[1][2] != '.')){
        if (board[1][2] == 'X') xf = true;
        else of = true;
    }
    if ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) && (board[2][2] != '.')){
        if (board[2][2] == 'X') xf = true;
        else of = true;
    }
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] != '.')){
        if (board[2][2] == 'X') xf = true;
        else of = true;
    }
    if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[0][2] != '.')){
        if (board[0][2] == 'X') xf = true;
        else of = true;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        string in;
        cin >> in;
        if (in == "end") break;
        vector<vector<char>> board(3, vector<char>(3));
        int xc = 0, oc = 0;
        bool flag = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = in[i * 3 + j];
                if (board[i][j] == 'X') xc++;
                else if (board[i][j] == 'O') oc++;
                else flag = true;
            }
        }
        check(board);
        if (flag && (!xf&&!of)) {
            cout << "invalid\n";
            continue;
        }
        if (of && xf) {
            cout << "invalid\n";
            continue;
        }
        if (of && xc != oc) {
            cout << "invalid\n";
            continue;
        }
        if (xf && xc != oc + 1) {
            cout << "invalid\n";
            continue;
        }
        if ((!xf && !of) && xc != oc + 1) {
            cout << "invalid\n";
            continue;
        }
        cout << "valid\n";
    }
}