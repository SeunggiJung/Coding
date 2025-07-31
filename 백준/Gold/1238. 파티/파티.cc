#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, X;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
vector<int> dist;
vector <bool> visited;
map<int, vector<pii>> m;

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int dijkstra_go(int start) {
    int cur = start;
    int w = 0;
    dist[cur] = 0;
    priority_queue<pii, vector<pii>, compare> pq;
    pq.push({ start,0 });
    while (!pq.empty()) {
        w = pq.top().second;
        cur = pq.top().first;
        pq.pop();
        if (cur == X) break;
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto& p : m[cur]) {
            if (p.second + w < dist[p.first]) {
                dist[p.first] = p.second + w;
            }
            pq.push({ p.first, dist[p.first] });
        }
    }
    return dist[cur];
}
int dijkstra_back(int start) {
    int cur = X;
    int w = 0;
    dist[cur] = 0;
    priority_queue<pii, vector<pii>, compare> pq;
    pq.push({ X,0 });
    while (!pq.empty()) {
        w = pq.top().second;
        cur = pq.top().first;
        pq.pop();
        if (cur == start) break;
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto& p : m[cur]) {
            if (p.second + w < dist[p.first]) {
                dist[p.first] = p.second + w;
            }
            pq.push({ p.first, dist[p.first] });
        }
    }
    return dist[cur];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> X;
    dist = vector<int>(N + 1,INT32_MAX);
    visited = vector<bool>(N + 1, false);
    int maxi = 0;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        m[a].push_back({ b,c });
    }
    for (int i = 1; i <= N; i++) {
        dist = vector<int>(N + 1, INT32_MAX);
        visited = vector<bool>(N + 1, false);
        int go = dijkstra_go(i);
        dist = vector<int>(N + 1, INT32_MAX);
        visited = vector<bool>(N + 1, false);
        int back = dijkstra_back(i);
        maxi = max(maxi, go + back);
    }
    cout << maxi;
}