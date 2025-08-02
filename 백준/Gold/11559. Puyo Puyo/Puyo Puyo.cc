#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
vector<vector<char>> board(12, vector<char>(6));
vector<vector<bool>> visited(12, vector<bool>(6,false));
queue<pii> bomb;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int bfs(char color, int r, int c) {
    queue<pii> q;
    q.push({ r,c });
    int cnt = 0;
    bomb = queue<pii>();
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        bomb.push({ x,y });
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];
            if (nr < 0 || nc < 0 || nr >= 12 || nc >= 6) continue;
            if (visited[nr][nc]) continue;
            if (board[nr][nc] != color) continue;
            q.push({ nr,nc });
        }
    }
    if (cnt >= 4) {
        while (!bomb.empty()) {
            board[bomb.front().first][bomb.front().second] = '.';
            bomb.pop();
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int left = 5, right = 0, top = 0;
    for (int i = 0; i < 12; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < 6; j++)
        {
            board[i][j] = in[j];
            if (board[i][j] != '.') {
                left = min(left, j);
                right = max(right, j);
                top = min(top, j);
            }
        }
    }
    int cnt = 0;
func:
    bool flag = false;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j <= 5; j++) {
            if (visited[i][j]) continue;
            if (board[i][j] != '.') {
                if (bfs(board[i][j], i, j) >= 4) 
                    flag = true;
            }
        }
    }
    if (flag) {
        for (int j = 0; j < 6; j++) {
            for (int i = 11; i > 0; i--) {
                if (board[i][j] == '.') {
                    int up = 1;
                    while (true) {
                        if (i - up < 0) break;
                        if (board[i - up][j] != '.') {
                            board[i][j] = board[i - up][j];
                            board[i - up][j] = '.';
                            break;
                        }
                        up++;
                    }
                }
            }
        }
        visited = vector<vector<bool>>(12, vector<bool>(6, false));
        cnt++;
        goto func;
    }
    cout << cnt;
}