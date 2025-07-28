#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
static int N, M, K;
vector<vector<pii>> v;
vector<int> out;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
void prim() {
    if (N == 1) {
        cout << out[1]; return;
    }
    vector<bool> visited(N + 1, false);
    vector<int> dist(N + 1, INT32_MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 1; i <= N; i++) {
        pq.push({ out[i], N+1, i });
    }
    int weight = 0;
    while (!pq.empty()) {
        int w = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();
        bool flag = false;
        if (visited[y]) continue;
        visited[y] = true;
        weight += w;
        for (auto& link : v[y]) {
            if (!visited[link.second] && link.first < dist[link.second]) {
                pq.push({ link.first, y, link.second });
                dist[link.second] = link.first;
            }
        }
    }
    cout << weight;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<vector<pii>>(N + 1);
    out = vector<int>(N + 1);
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back({ w,y });
        v[y].push_back({ w,x });
    }
    for (int i = 1; i <= N; i++) {
        cin >> out[i];
    }
    prim();
}