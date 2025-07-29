#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
int N, K;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    vector<vector<char>> board(N, vector<char>(K));
    vector < vector < bool>> land(N, vector<bool>(K, false));
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < K; j++) {
            board[i][j] = in[j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (board[i][j] == 'X') {
                land[i][j] = true;
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr < 0 || nc < 0 || nr >= N || nc >= K) {
                        cnt++; continue;
                    }
                    if (board[nr][nc] == '.') cnt++;
                }
                if (cnt >= 3) land[i][j] = false;
            }
        }
    }
    int left = 11, right = 0;
    int top = 11, bottom = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (land[i][j]) {
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bottom = max(bottom, i);
            }
        }
    }
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (land[i][j]) cout << "X";
            else cout << ".";
        }
        cout << "\n";
    }
}