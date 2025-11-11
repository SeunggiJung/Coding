#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<char>> board(N, vector<char>(2 * N - 1, ' '));
    board[0][N - 1] = '*';
    board[1][N - 2] = '*';
    board[1][N] = '*';
    for (int i = 0; i < 5; ++i) {
        board[2][N - 3 + i] = '*';
    }

    for (int k = 3; k < N; k *= 2) {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 2 * k - 1; ++j) {
                if (board[i][N - k + j] == '*') {
                    board[i + k][N - 2 * k + j] = '*';
                    board[i + k][N + j] = '*';
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2 * N - 1; ++j) {
            cout << board[i][j];
        }
        cout<<"\n";
    }
}