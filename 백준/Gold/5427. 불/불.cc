#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
static int N, w,h;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
vector<vector<char>> v;
vector<vector<long long>> visited;
queue<pii> fire;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void bfs(pii start) {
    visited = vector<vector<long long>>(h, vector<long long>(w, 0));
    queue<vector<int>> q;
    while (!fire.empty()) {
        q.push({ fire.front().first, fire.front().second ,1});
        fire.pop();
    }
    q.push({ start.first, start.second,0 });
    while (!q.empty()) {
        int r = q.front()[0];
        int c = q.front()[1];
        int f = q.front()[2];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (f==1) {
                if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
                if (v[nr][nc] == '.') {
                    v[nr][nc] = '*';
                    q.push({ nr, nc, 1 });
                }
            }
            else {
                if (nr < 0 || nc < 0 || nr >= h || nc >= w) {
                    cout << visited[r][c] + 1 << "\n";
                    return;
                }
                if (visited[nr][nc]) continue;
                if (v[nr][nc] == '.') {
                    q.push({nr,nc,0});
                    visited[nr][nc] = visited[r][c] + 1;
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    while (N-- > 0) {
        cin >> w >> h;
        v = vector<vector<char>>(h, vector<char>(w, ' '));
        string in;
        pii start;
        fire = queue<pii>();
        for (int i = 0; i < h; i++) {
            cin >> in;
            for (int j = 0; j < w; j++) {
                v[i][j] = in[j];
                if (in[j] == '@') start = make_pair(i, j);
                if (in[j] == '*') fire.push(make_pair(i, j));
            }
        }
        bfs(start);
    }
}