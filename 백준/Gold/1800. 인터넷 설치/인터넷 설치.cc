#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, P, K;
vector<vector<pii>> graph;
vector<int> dist;
void dijkstra(int x) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0,1 });
    while (!pq.empty()) {
        int c = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (dist[c] < weight) continue;
        for (auto& n : graph[c]) {
            int next = n.first;
            int nw = n.second;
            int w = weight + (nw > x); // weight -> 개수, nm>x -> 다음으로 추가할 간선이 x보다 크면 1 아니면 0 추가
            if (dist[next] > w) {
                dist[next] = w;
                pq.push({ w, next });
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> P >> K;
    graph = vector<vector<pii>>(N + 1);
    dist = vector<int>(N + 1, 0);
    for (int i = 0; i < P; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }
    int able = -1, disable = 10000000, answer = -1;
    while (able + 1 < disable) {
        int mid = (able + disable) / 2;
        dist = vector<int>(N + 1,mid+1);
        dijkstra(mid);
        if (dist[N] <= K) {
            disable = mid;
            answer = mid;
        }
        else
            able = mid;
    }
    cout << answer;
}