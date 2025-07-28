#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
static int N, M, ans;
vector<vector<char>> v;
vector<vector<bool>> check;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void dfs(int r, int c, int moves) {
    if (moves >= ans) return;
    bool flag = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= M || v[nr][nc] == '*' || check[nr][nc]) continue;
        flag = false;
        check[nr][nc] = true;
        while (true) {
            nr += dr[i];
            nc += dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M || v[nr][nc] == '*' || check[nr][nc]) {
                nr -= dr[i];
                nc -= dc[i];
                break;
            }
            check[nr][nc] = true;
        }
        dfs(nr, nc, moves + 1);
        while (true) {
            if (nr == r && nc == c) break;
            check[nr][nc] = false;
            nr -= dr[i];
            nc -= dc[i];
        }
    }
    if (flag) {
        bool clear = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j] == '*') continue;
                if (!check[i][j]) {
                    clear = false;
                    break;
                }
            }
        }
        if (clear) {
            ans = min(ans, moves);
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cases = 1;
    while (cin >> N >> M) {
        v = vector<vector<char>>(N, vector<char>(M));
        check = vector<vector<bool>>(N, vector<bool>(M, false));
        ans = 1000001;
        for (int i = 0; i < N; i++) {
            string in;
            cin >> in;
            for (int j = 0; j < M; j++) {
                v[i][j] = in[j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j] == '.') {
                    check[i][j] = true;
                    dfs(i, j, 0);
                    check[i][j] = false;
                }
            }
        }
        if (ans == 1000001) ans = -1;
        cout << "Case " << cases++ << ": " << ans << "\n";
    }
}