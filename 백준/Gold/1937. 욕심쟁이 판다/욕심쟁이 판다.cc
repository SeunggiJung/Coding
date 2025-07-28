#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> v;
vector<vector<int>> dp;
int N;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
int maxi = 1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    v = vector<vector<int>>(N, vector<int>(N));
    dp = vector<vector<int>>(N, vector<int>(N, 1));
    vector<int> xy(3);
    priority_queue<vector<int>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            pq.push({ v[i][j], i, j });
        }
    }
    while (!pq.empty()) {
        int x = pq.top()[1], y = pq.top()[2];
        int w = pq.top()[0];
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (v[nr][nc] > v[x][y]) {
                dp[x][y] = max(dp[nr][nc] + 1, dp[x][y]);
                maxi = max(dp[x][y], maxi);
            }
        }
    }
    cout << maxi;
}