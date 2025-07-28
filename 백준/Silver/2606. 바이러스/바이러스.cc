#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M,K;
static vector<vector<int>> v;
static vector<bool> visited;
static vector<int> out;
static vector<bool> kn;
struct compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};
void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            if (visited[v[x][i]])continue;
            q.push(v[x][i]);
            visited[v[x][i]] = true;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    visited = vector<bool>(N + 1, false);
    v = vector<vector<int>>(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[1] = true;
    bfs();
    int cnt = 0;
    for (int i = 2; i < N + 1; i++) {
        if (visited[i])cnt++;
    }
    cout << cnt;
}
