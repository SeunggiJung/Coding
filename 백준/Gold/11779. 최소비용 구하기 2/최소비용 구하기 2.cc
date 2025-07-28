#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
static int N, M, K;
vector<pii> dist;
vector <bool> visited;
map<int, vector<pii>> m;
vector<int> out;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void dijkstra(int start, int end) {
    int cur = start;
    int w = 0;
    dist[cur].first = 0;
    priority_queue<pii, vector<pii>, compare> pq;
    pq.push({ start,0 });
    while (!pq.empty()) {
        w = pq.top().second;
        cur = pq.top().first;
        pq.pop();
        if (cur == end) break;
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto& p : m[cur]) {
            if (visited[p.first]) continue;
            if (p.second + w < dist[p.first].first) {
                dist[p.first].first = min(dist[p.first].first, p.second + w);
                dist[p.first].second = cur;
            }
            pq.push({ p.first, dist[p.first].first });
        }
    }
    cout << dist[cur].first << "\n";
    out.push_back(cur);
    while (cur != start) {
        cur = dist[cur].second;
        out.push_back(cur);
    }
    cout << out.size() << "\n";
    while (!out.empty()) {
        cout << out.back() << " ";
        out.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    dist = vector<pii>(N + 1, { 100000001,0 });
    visited = vector<bool>(N + 1, false);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        m[a].push_back({ b,c });
        //m[b].push_back({ a,c });
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start, end);
}