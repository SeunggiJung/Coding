#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int V, E, P;
vector<bool> visited;
vector<int> dist;
typedef pair<int, int> pii;
map<int, vector<pii>> line;
int goal;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
int dijkstra(int start, int end) {
    dist = vector<int>(V + 1, INT32_MAX);
    visited = vector<bool>(V + 1, false);
    int cur = start;
    int w = 0;
    dist[cur] = w;
    priority_queue<pii, vector<pii>, compare> pq;
    pq.push({ cur,w });
    bool flag = false;
    while (true) {
        if (pq.empty()) break;
        w = pq.top().second;
        cur = pq.top().first;
        pq.pop();
        if (cur == end) break;
        if (visited[cur])continue;
        visited[cur] = true;
        for (auto& p : line[cur]) {
            if (visited[p.first])continue;
            dist[p.first] = min(dist[p.first], p.second + w);
            pq.push({ p.first, dist[p.first] });
        }
    }
    return dist[end];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> V >> E >> P;
    goal = V;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        line[a].push_back({ b,c });
        line[b].push_back({ a,c });
    }
    int total = dijkstra(1, goal);
    int mid = dijkstra(1, P);
    int end = dijkstra(P, goal);
    if (total >=  mid + end) cout << "SAVE HIM";
    else cout << "GOOD BYE";
}