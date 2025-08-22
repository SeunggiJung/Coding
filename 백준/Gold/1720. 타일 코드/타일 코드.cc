#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    if (N == 1) {
        cout << 1;
        return 0;
    }
    if (N == 2) {
        cout << 3;
        return 0;
    }
    vector<vector<int>> board(N+1, vector<int>(2, 0)); // 0: 세로, 1: 가로
    board[1][0] = 1;
    board[2][0] = 1;
    board[2][1] = 2;
    for (int i = 3; i <= N; i++) {
        board[i][0] = board[i - 1][0] + board[i - 1][1];
        board[i][1] = (board[i - 2][0] + board[i - 2][1]) * 2;
    }
    int total = board[N][0] + board[N][1];
    int nonconflicts = 0;
    if (N % 2==1) {
        nonconflicts = board[N / 2][0] + board[N / 2][1];
    }
    else {
        nonconflicts = board[N / 2][0] + board[N / 2][1] + board[N / 2 + 1][1];
    }
    cout << total - (total - nonconflicts) / 2;
}