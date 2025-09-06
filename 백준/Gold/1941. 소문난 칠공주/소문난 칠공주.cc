#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<vector<char>> board(5, vector<char>(5));
vector<vector<bool>> visited;
map<vector<pii>, bool> check;
int cnt = 0;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
void bt(int depth, int ds, vector<pii> route) {
    if (depth == 7) {
        sort(route.begin(), route.end());
        if (ds>=4 && !check[route]) {
            check[route] = true;
            cnt++;
        }
        return;
    }
    for (int j = 0; j < route.size(); j++) {
        int x = route[j].first;
        int y = route[j].second;
        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];
            if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5) continue;
            if (visited[nr][nc]) continue;
            visited[nr][nc] = true;
            route.push_back({ nr,nc });
            if (board[nr][nc] == 'S') bt(depth + 1, ds + 1, route);
            else bt(depth + 1, ds, route);
            route.pop_back();
            visited[nr][nc] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string input;
    for (int i = 0; i < 5; i++) {
        cin >> input;
        for (int j = 0; j < 5; j++) {
            board[i][j] = input[j];
        }
    }
    visited = vector<vector<bool>>(5, vector<bool>(5, false));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            visited[i][j] = true;
            if (board[i][j] == 'S') bt(1, 1, { {i,j} });
            visited = vector<vector<bool>> (5, vector<bool>(5, false));
        }
    }
    cout << cnt;
}