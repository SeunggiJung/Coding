#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> board;
int N, x, y, d, g;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
vector<vector<int>> directions;
int count() {
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j]==1 && board[i + 1][j]==1 && board[i][j + 1]==1 && board[i + 1][j + 1]==1) cnt++;
        }
    }
    return cnt;
}
void func(int r, int c, vector<int> dir) {
    int rx = r;
    int ry = c;
    for (auto& a : dir) {
        rx += dx[(d+a)%4];
        ry += dy[(d+a)%4];
        if (rx > 101 || ry > 101 || rx < 0 || ry < 0) continue;
        board[rx][ry] = 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    board = vector<vector<int>>(101, vector<int>(101, 0));
    directions.push_back({ 0 });

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        board[x][y] = 1;
        if (directions.size() > g) {
            func(x, y, directions[g]);
            continue;
        }
        for (int j = directions.size(); j <= g; j++) {
            directions.push_back({ directions[j - 1] });
            for (int k = directions[j - 1].size() - 1; k >= 0; k--) {
                directions[j].push_back((directions[j - 1][k] + 1) % 4);
            }
        }
        func(x, y, directions[g]);
    }
    cout << count();
}