#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <time.h>
#include <list>
using namespace std;
static long long int N, M, A;
static vector<vector<int>> v;
static vector<vector<bool>> visited;
static int cnt;
map<int, vector<int>> m;
static int maxi;
vector<int> result;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void bfs(int x, int y) {
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({ x,y });
    v[x][y] = 0;
    int dr[] = { 1,-1,0,0 };
    int dc[] = { 0,0,-1,1 };
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr<0 || nc<0 || nr>M || nc>N || !v[nr][nc])continue;
            q.push({ nr,nc });
            v[nr][nc] = 0;
        }
    }
    result.push_back(cnt);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> A;
    v = vector<vector<int>>(M+1, vector<int>(N+1, 1));
    visited = vector<vector<bool>>(M + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < A; i++) {
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        for (int j = x+1; j <= z; j++) {
            for (int k = y+1; k <= w; k++) {
                v[j][k] = 0;
            }
        }
    }
    for (int i = 0; i <= M; i++) {
        v[i][0] = 0;
    }
    for (int j = 0; j <= N; j++) {
        v[0][j] = 0;
    }
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            if (v[i][j]==0)continue;
            bfs(i, j);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
