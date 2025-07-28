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
static long long int N, M;
static vector<vector<int>> v;
static vector<bool> visited;
static int cnt;
map<int, vector<int>> m;
void bfs(int x) {
    if (visited[x]) return;
    cnt++;
    visited[x] = true;
    queue<int> q;
    for (int i = 0; i < m[x].size(); i++) {
        q.push(m[x][i]);
    }
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if (visited[n])continue;
        visited[n] = true;
        for (int i = 0; i < m[n].size(); i++) {
            q.push(m[n][i]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    visited = vector<bool>(N + 1);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    cnt = 0;
    for (int i = 1; i <= N; i++) {
        bfs(i);
    }
    cout << cnt;
}
