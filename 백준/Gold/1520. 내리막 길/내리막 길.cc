#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));
    vector<vector<int>> dp(N, vector<int>(M,0));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            pq.push({ board[i][j], i,j });
        }
    }
    dp[N-1][M-1] = 1;
    while (!pq.empty()) {
        int w = pq.top()[0];
        int r = pq.top()[1];
        int c = pq.top()[2];
        pq.pop();
        if (w >= board[0][0] || w < board[N - 1][M - 1]) continue;
        if (w == board[N - 1][M - 1] && (r != N - 1 || c != M - 1)) continue;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (board[nr][nc] > board[r][c]) {
                dp[nr][nc] += dp[r][c];
            }
        }
    }
    cout << dp[0][0];
}