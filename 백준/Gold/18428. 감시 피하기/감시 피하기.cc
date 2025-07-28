#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
static int N;
vector<vector<char>> v;
vector<vector<bool>> visited;
vector<pair<int, int>> teachers;
static bool result;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void bt(int depth) {
    if (depth == 3) {
        int dr[] = { 1,-1,0,0 };
        int dc[] = { 0,0,-1,1 };
        bool flag = true;
        for (pair<int, int> xy : teachers) {
            int x = xy.first;
            int y = xy.second;
            for (int i = 0; i < 4; i++) {
                int nx = x;
                int ny = y;
                while (true) {
                    nx += dr[i];
                    ny += dc[i];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N || v[nx][ny] == 'O') break;
                    if (v[nx][ny] == 'S') flag = false;
                }
            }
        }
        if (flag) result = true;
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || v[i][j] != 'X') continue;
            visited[i][j] = true;
            v[i][j] = 'O';
            bt(depth + 1);
            v[i][j] = 'X';
            visited[i][j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    v = vector<vector<char>>(N, vector<char>(N));
    visited = vector<vector<bool>>(N, vector < bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'T') teachers.push_back({ i,j });
        }
    }
    result = false;
    bt(0);
    if (result) cout << "YES";
    else cout << "NO";
}
