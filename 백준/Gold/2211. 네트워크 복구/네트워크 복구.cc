#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
vector<int> dist;
map<int, vector<pii>> m;
int N, M;
struct compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
    }
};
void dijkstra() {
    vector<pii> ans;
    int cur = 1;
    int w = 0;
    dist[cur] = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({ 0,1,0 }); // 1. 가중치, 2. 현재, 3. 어디서
    while (!pq.empty()) {
        w = pq.top()[0];
        cur = pq.top()[1];
        int pre = pq.top()[2];
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        if(pre!=0) ans.push_back({ pre,cur });
        for (auto& p : m[cur]) {
            if (visited[p.first]) continue;
            if (p.second + w < dist[p.first]) {
                dist[p.first] = min(dist[p.first], p.second + w);
                pq.push({ dist[p.first], p.first, cur });
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto& p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    dist = vector<int>(N + 1, INT32_MAX);
    visited = vector<bool>(N + 1, false);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        m[a].push_back({ b,c });
        m[b].push_back({ a,c });
    }
    dijkstra();
}