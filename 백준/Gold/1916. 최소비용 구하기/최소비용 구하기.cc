#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;
int INF = INT32_MAX;
int N, M;
int start, goal;
vector<int> dist;
map<int, vector<pair<int, int>>> m;
vector<bool> visited;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void dijkstra() {
    int cur = start;
    int w = 0;
    dist[cur] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({ start,0 });
    while (true) {
        if (pq.empty()) break;
        w = pq.top().second;
        cur = pq.top().first;
        pq.pop();
        if (visited[cur])continue;
        visited[cur] = true;
        if (cur == goal) break;
        for (auto& p : m[cur]) {
            if (visited[p.first])continue;
            dist[p.first] = min(dist[p.first], p.second + w);
            pq.push({p.first, dist[p.first]});
        }
        
    }
    cout << dist[goal];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    dist = vector<int>(N + 1, INF);
    visited = vector<bool>(N + 1, false);
    for (int i = 0; i < M; i++) {
        int S, G, W;
        cin >> S >> G >> W;
        m[S].push_back({ G,W });
    }
    cin >> start >> goal;
    dijkstra();
}