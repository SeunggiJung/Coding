#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <random>
using namespace std;
static int R, C, T;
static vector<vector<int>> v;
static vector<vector<bool>> visited;
static vector<int> scores;
int cnt;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cnt = 0;
    cin >> R >> C >> T;
    v = vector<vector<int>>(R, vector<int>(C));
    vector<pair<int, int>> cleaner;
    queue<pair<int, int>> dust;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> v[i][j];
            if (v[i][j] == -1) {
                cleaner.push_back({i,j});
            }
            else if (v[i][j] > 0) dust.push({ i,j });
        }
    }
    
    int dr[] = { 1,-1,0,0 };
    int dc[] = { 0,0,-1,1 };
    while (T--) {
        queue<pair<pair<int, int>, int>> q;
        while (!dust.empty()) {
            int r = dust.front().first;
            int c = dust.front().second;
            dust.pop();
            cnt = 0;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= R || nc >= C || v[nr][nc] == -1) continue;
                q.push({{ nr,nc }, v[r][c] / 5});
                cnt++;
            }
            v[r][c] -= v[r][c] / 5 * cnt;
        }
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            v[r][c] += d;
        }
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                int r = cleaner[0].first-1;
                int c = cleaner[0].second;
                v[r][c] = 0;
                while (r > 0) {
                    v[r][c] = v[r-1][c];
                    r = r - 1;
                    v[r][c] = 0;
                }
                while (c < C - 1) {
                    v[r][c] = v[r][c+1];
                    c = c + 1;
                    v[r][c] = 0;
                }
                while (r < cleaner[i].first) {
                    v[r][c] = v[r+1][c];
                    r = r + 1;
                    v[r][c] = 0;
                }
                while (c>1) {
                    v[r][c] = v[r][c-1];
                    c = c - 1;
                    v[r][c] = 0;
                }
            }
            else {
                int r = cleaner[1].first + 1;
                int c = cleaner[1].second;
                v[r][c] = 0;
                while (r < R - 1) {
                    v[r][c] = v[r+1][c];
                    r = r + 1;
                    v[r][c] = 0;
                }
                
                while (c < C - 1) {
                    v[r][c] = v[r][c+1];
                    c = c + 1;
                    v[r][c] = 0;
                }
                while (r > cleaner[i].first){
                    v[r][c] = v[r-1][c];
                    r = r - 1;
                    v[r][c] = 0;
                }
                while (c>1) {
                    v[r][c] = v[r][c-1];
                    c = c - 1;
                    v[r][c] = 0;
                }
            }
        }
        dust = queue<pair<int, int>>();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (v[i][j] > 0) dust.push({ i,j });
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] == -1) continue;
            sum += v[i][j];
        }
    }
    cout << sum;
    
}
