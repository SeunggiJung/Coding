#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
vector<int> v;
int N, M, T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> T;
    vector<vector<bool>> visited(2, vector<bool>(N + 1, false));
    map<int, vector<int>> m;
    map<int, bool> cycle;
    vector<int> duck(T);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    for (int i = 0; i < T; i++) {
        cin >> duck[i];
        cycle[duck[i]] = true;
    }
    queue<vector<int>> q; // 1. 좌표, 2. 시간
    q.push({ 1,0 });
    int mini = 1001;
    while (!q.empty()) {
        int node = q.front()[0];
        int time = q.front()[1];
        int ride = 0;
        if (node == N) {
            cout << time;
            return 0;
        }
        q.pop();
        if (duck[time % T] == node) ride = 1;
        visited[ride][node] = true;
        if (ride) {
            q.push({ duck[(time + 1) % T], time + 1, ride });
        }
        else {
            for (auto& next : m[node]) {
                if (visited[ride][next]) continue;
                q.push({ next, time + 1, ride });
            }
            if (cycle[node]) q.push({ node, time + 1, ride });
        }
    }
    cout << -1;
}