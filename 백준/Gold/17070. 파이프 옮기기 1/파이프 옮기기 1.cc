#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
static int N, M;
vector<int> parent;
int dr[] = { 0,1,1 };
int dc[] = { 1,0,1 };
vector<vector<vector<int>>> dp;
vector<vector<int>> v;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
bool check(int r, int c, int d) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (nr < 0 || nc < 0 || nr >= N || nc >= N || v[nr][nc]==1) return false;
    if (d == 2) {
        if (v[r + 1][c]==1 || v[r][c + 1]==1) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    v = vector<vector<int>>(N, vector<int>(N));
    dp = vector<vector<vector<int>>>(3,vector<vector<int>>(N, vector<int>(N, 0)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    dp[0][0][1] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 3; k++) {
                if (!dp[k][i][j]) continue;
                if (k == 0) {
                    if (check(i, j, 0)) { dp[0][i][j + 1] += dp[k][i][j];}
                    if (check(i, j, 2)) { dp[2][i + 1][j + 1] += dp[k][i][j];}
                }
                if (k == 1) {
                    if (check(i, j, 1)) { dp[1][i + 1][j] += dp[k][i][j];}
                    if (check(i, j, 2)) { dp[2][i + 1][j + 1] += dp[k][i][j];}
                }
                if (k == 2) {
                    if (check(i, j, 0)) { dp[0][i][j + 1] += dp[k][i][j];}
                    if (check(i, j, 1)) { dp[1][i + 1][j] += dp[k][i][j];}
                    if (check(i, j, 2)) { dp[2][i + 1][j + 1] += dp[k][i][j];}
                }
            }
        }
    }
    cout << dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1];
}