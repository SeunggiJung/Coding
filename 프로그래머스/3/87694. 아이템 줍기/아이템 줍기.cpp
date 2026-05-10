#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> board;
vector<vector<int>> cnt;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    board.assign(101, vector<int>(101,0));
    cnt.assign(101, vector<int>(101, 0));
    for (auto& rect : rectangle) {
        int x1 = rect[0] * 2, y1 = rect[1] * 2;
        int x2 = rect[2] * 2, y2 = rect[3] * 2;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                board[i][j] = 1;
            }
        }
    }
    for (auto& rect : rectangle) {
        int x1 = rect[0] * 2, y1 = rect[1] * 2;
        int x2 = rect[2] * 2, y2 = rect[3] * 2;
        
        for (int i = x1 + 1; i < x2; i++) {
            for (int j = y1 + 1; j < y2; j++) {
                board[i][j] = 0;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({characterX * 2, characterY * 2});
    cnt[characterX * 2][characterY * 2] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == itemX * 2 && y == itemY * 2) return (cnt[x][y]) / 2;
        for (int i = 0; i < 4; i++) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            if (nx < 0 || ny < 0 || nx > 100 || ny > 100) continue;
            if (board[nx][ny] == 1 && cnt[nx][ny] == 0) {
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return 0;
}