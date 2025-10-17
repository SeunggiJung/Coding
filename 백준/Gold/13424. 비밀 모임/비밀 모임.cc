#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int T, N, M, K;
int a, b, c;
vector<int> dist;
vector<bool> visited;
map<int, vector<pii>> m;
struct compare {
    bool operator()(const pair<int, long double>& a, const pair<int, long double>& b) {
        return a.second > b.second;
    }
};
void dijkstra(int start) {
    visited = vector<bool>(N + 1, false);
    dist = vector<int>(N + 1, INT32_MAX);
    int cur = start;
    int w = 0;
    dist[cur] = 0;
    priority_queue<pii, vector<pii>, compare> pq;
    pq.push({ cur,w });
    while (!pq.empty()) {
        w = pq.top().second;
        cur = pq.top().first;
        pq.pop();
        if (visited[cur])continue;
        visited[cur] = true;
        for (auto& p : m[cur]) {
            if (visited[p.first])continue;
            if (dist[p.first] > p.second + w) {
                dist[p.first] = p.second + w;
            }
            pq.push({ p.first, dist[p.first] });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N >> M;
        m.clear();
        vector<int> dist_sum(N + 1, 0);
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            m[a].push_back({ b,c });
            m[b].push_back({ a,c });
        }
        cin >> K;
        int f;
        for (int i = 0; i < K; i++) {
            cin >> f;
            dijkstra(f);
            for (int i = 1; i <= N; i++) {
                dist_sum[i] += dist[i];
            }
        }
        int mini = INT32_MAX;
        int ans;
        for (int i = 1; i <= N; i++) {
            if (dist_sum[i] < mini) {
                mini = dist_sum[i];
                ans = i;
            }
        }
        cout << ans << "\n";
    }
}

