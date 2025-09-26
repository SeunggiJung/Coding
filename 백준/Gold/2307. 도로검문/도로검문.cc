#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
//1. 루트 기억하면서 최단 경로 구하기
//2. 루트 하나씩 지워보면서 최단 경로 다 구해보기
//3. (2에서 구한 모든 최단 경로 - 1에서 구한 최단 경로)의 최대값 구하기.
using namespace std;
typedef pair<int, int> pii;
vector<int> dist;
map<int, vector<pair<int, int>>> m;
vector<bool> visited;
vector<int> route;
int N, M;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int dijkstra(pii disturb) {
    int cur = 1;
    int w = 0;
    dist[cur] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({ 1,0 });
    while (!pq.empty()) {
        w = pq.top().second;
        cur = pq.top().first;
        pq.pop();
        if (visited[cur])continue;
        visited[cur] = true;
        for (auto& p : m[cur]) {
            if (visited[p.first])continue;
            if ((cur == disturb.first && p.first == disturb.second) || (cur == disturb.second && p.first == disturb.first)) continue;
            if (dist[p.first] > p.second + w) {
                route[p.first] = cur;
                dist[p.first] = p.second + w;
            }
            pq.push({ p.first, dist[p.first] });
        }
    }
    return dist[N];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    dist = vector<int>(N + 1, INT32_MAX);
    visited = vector<bool>(N + 1, false);
    route = vector<int>(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        m[a].push_back({ b,t });
        m[b].push_back({ a,t });
    }
    int min_time;
    min_time = dijkstra({0,0});
    vector<int> path;
    int cur = N;
    while (true) {
        path.push_back(cur);
        if (cur == 1) break;
        cur = route[cur];
    }
    int max_time = 0;
    bool flag = false;
    for (int i = 0; i < path.size()-1; i++) {
        dist = vector<int>(N + 1, INT32_MAX);
        visited = vector<bool>(N + 1, false);
        int d_time = dijkstra({ path[i], path[i + 1] });
        if (d_time == INT32_MAX) {
            flag = true; continue;
        }
        max_time = max(d_time - min_time, max_time);
    }
    if (flag) cout << -1;
    else cout << max_time;
}