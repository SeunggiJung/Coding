#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
static int N, M;
vector<int> dist;
vector<bool> visited;
map<int, vector<pii>> m;

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void dijkstra(int start, int end) {
    int cur = start;
    int w = 0;
    dist[cur] = 0;
    priority_queue<pii, vector<pii>, compare> pq;
    pq.push({ start,0 });
    while (!pq.empty()) {
        w = pq.top().second;
        cur = pq.top().first;
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto& p : m[cur]) {
            if (visited[p.first]) continue;
            dist[p.first] = min(dist[p.first], p.second + w);
            pq.push({ p.first, dist[p.first] });
        }
    }
    cout << dist[end];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    dist = vector<int>(N+1, 99999999);
    visited = vector<bool>(N+1, false);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        m[a].push_back({ b,c });
        m[b].push_back({ a,c });
    }
    int s, e;
    cin >> s >> e;
    dijkstra(s, e);
}