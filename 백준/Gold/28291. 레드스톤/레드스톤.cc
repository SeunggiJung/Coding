#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M, T;
vector<vector<int>> board;
vector<vector<int>> visited;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
int mini = INT32_MAX;
vector<pair<int, int>> block;
map<pair<int, int>, bool> m;
int total = 0;
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    board = vector<vector<int>>(N, vector<int>(M,0));
    visited= vector<vector<int>>(N, vector<int>(M, 0));
    cin >> T;
    for (int i = 0; i < T; i++) {
        string in;
        int x, y;
        cin >> in >> x >> y;
        switch (in[9]) {
        case 'b':
            board[x][y] = -1;
            block.push_back({ x,y });
            break;
        case 'd':
            board[x][y] = 1;
            break;
        case 'l':
            board[x][y] = -2;
            total++;
            break;
        }
    }
    queue<pair<int, int>> q;
    for (auto& p : block) {
        int r = p.first;
        int c = p.second;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M||!board[nr][nc]) continue;
            if (board[nr][nc] == 1) {
                visited[nr][nc] = 15;
                q.push({ nr,nc });
            }
            else if (board[nr][nc]==-2) {
                if (!m[{nr, nc}]) {
                    cnt++;
                    m[{nr, nc}] = true;
                }
            }
        }
    }
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (visited[r][c] - 1 == 0) continue;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M || !board[nr][nc]) continue;
            if (board[nr][nc] == -2) {
                if (!m[{nr, nc}]) {
                    cnt++;
                    m[{nr, nc}] = true;
                }
                continue;
            }
            if (visited[nr][nc] > visited[r][c] - 1)continue;
            q.push({ nr,nc });
            visited[nr][nc] = visited[r][c] - 1;
        }
    }
    if (cnt == total)cout << "success";
    else cout << "failed";
}
