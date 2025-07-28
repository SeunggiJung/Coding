#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M, T;
vector<vector<char>> board;
typedef pair<int, int> pii;
map<pair<pii, pii>, int> visited;
vector<pii> coin;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};
bool checkout(pii n) {
    if (n.first < 0 || n.second < 0 || n.first >= N || n.second >= M) return true;
    else return false;
}
void bfs() {
    pii c1 = coin[0];
    pii c2 = coin[1];
    queue<pair<pii, pii>> q;
    q.push({ c1, c2 });
    visited[{c1, c2}] = 1;
    while (!q.empty()) {
        c1 = q.front().first;
        c2 = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii n1 = { c1.first + dr[i], c1.second + dc[i] };
            pii n2 = { c2.first + dr[i], c2.second + dc[i] };
            if ((checkout(n1) && !checkout(n2)) || (!checkout(n1) && checkout(n2))) {
                if (visited[{c1, c2}] > 10) cout << -1;
                else cout << visited[{c1, c2}];
                return;
            }
            else if (checkout(n1) && checkout(n2)) continue;
            if (board[n1.first][n1.second] == '#') n1 = c1;
            if (board[n2.first][n2.second] == '#') n2 = c2;
            if (visited[{n1, n2}]) continue;
            visited[{n1, n2}] = visited[{c1, c2}] + 1;
            q.push({ n1,n2 });
        }
    }
    cout << -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    board = vector<vector<char>>(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < M; j++) {
            board[i][j] = in[j];
            if (in[j] == 'o') coin.push_back({ i,j });
        }
    }
    bfs();
}