#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
static int N, M;
vector<pair<int, int>> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<pair<int, int>>(N);
    vector<vector<int>> dp(N + 1, vector<int>(M+1,0));
    for (int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;
        v[i] = { W,V };
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < v[i].first; j++) {
            dp[i + 1][j] = dp[i][j];
        }
        for (int j = v[i].first; j <= M; j++) {
            dp[i+1][j] = max(dp[i][j], v[i].second + dp[i][j - v[i].first]);
        }
    }
    cout << dp[N][M];
}