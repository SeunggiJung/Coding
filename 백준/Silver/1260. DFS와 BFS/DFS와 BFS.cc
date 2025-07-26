#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M,K;
static vector<vector<int>> v;
static vector<bool> visited1;
static vector<bool> visited2;
static vector<int> out;
static vector<bool> kn;
static int cnt;
struct compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited1[start] = true;
    while (!q.empty()) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            if (visited1[v[x][i]])continue;
            q.push(v[x][i]);
            visited1[v[x][i]] = true;
        }
    }
}
void dfs(int depth) {
    if (depth == cnt) {
        for (int i = 1; i < cnt; i++) {
            cout << out[i] << " ";
        }
        return;
    }
    int tail = out.back();
    bool flag = false;
    for (int i = 0; i < v[tail].size(); i++) {
        if (visited2[v[tail][i]]) continue;
        flag = true;
        out.push_back(v[tail][i]);
        visited2[v[tail][i]] = true;
        dfs(out.size());
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> K;
    v = vector<vector<int>>(N + 1);
    visited1 = vector<bool>(N + 1, false);
    visited2 = vector<bool>(N + 1, false);
    vector<bool> visited(N + 1, false);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        visited[a] = true;
        visited[b] = true;
    }
    cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) cnt++;
    }
    for (int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end());
    }
    out.push_back(K);
    visited2[K] = true;
    cout << K << " ";
    dfs(1);
    cout << "\n";
    bfs(K);
    
}
