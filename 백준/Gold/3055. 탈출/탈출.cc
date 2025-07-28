#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
int R, C;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
vector<vector<char>> board;
vector<vector<int>> dochi;
queue<pii> water;
pii start, dest;
void bfs() {
    queue<vector<int>> q; // 0:r, 1:c, 2:도치 or 물
    q.push({ start.first, start.second, 0 });
    while (!water.empty()) {
        q.push({ water.front().first, water.front().second, 1 });
        water.pop();
    }
    while (!q.empty()) {
        int r = q.front()[0];
        int c = q.front()[1];
        int who = q.front()[2];
        q.pop();
        if (who) {
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
                if (board[nr][nc] == '*' || board[nr][nc] == 'X' || board[nr][nc] == 'D') continue;
                board[nr][nc] = '*';
                q.push({ nr,nc,1 });
            }
            continue;
        }
        if (board[r][c] == 'D') break;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if (board[nr][nc] == '*' || board[nr][nc] == 'X') continue;
            bool flag = false;
            for (int j = 0; j < 4; j++) {
                int nnr = nr + dr[j];
                int nnc = nc + dc[j];
                if (nnr < 0 || nnc < 0 || nnr >= R || nnc >= C) continue;
                if (board[nnr][nnc] == '*') {
                    flag = true; 
                }
            }
            if (flag) continue;
            if (dochi[nr][nc] <= dochi[r][c] + 1) continue;
            q.push({ nr,nc,0 });
            dochi[nr][nc] = dochi[r][c] + 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        int x = dest.first + dr[i];
        int y = dest.second + dc[i];
        if (x < 0 || y < 0 || x >= R || y >= C) continue;
        dochi[dest.first][dest.second] = min(dochi[dest.first][dest.second], dochi[x][y] + 1);
    }
    if (dochi[dest.first][dest.second] == 2501) cout << "KAKTUS";
    else cout << dochi[dest.first][dest.second];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> R >> C;
    board = vector<vector<char>>(R, vector<char>(C));
    dochi = vector<vector<int>>(R, vector<int>(C,2501));
    for (int i = 0; i < R; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < C; j++) {
            board[i][j] = input[j];
            if (board[i][j] == 'S') {
                start = { i,j };
                dochi[i][j] = 0;
                board[i][j] = '.';
            }
            if (board[i][j] == '*') water.push({ i,j });
            if (board[i][j] == 'D') dest = { i,j };
        }
    }
    bfs();
}