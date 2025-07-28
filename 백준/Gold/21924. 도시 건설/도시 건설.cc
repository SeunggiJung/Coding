#include <iostream>
#include <queue>
#include <map>
using namespace std;
static long long int sum;
static int N;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

void func(map<int, vector<pair<int, int>>> m) {
    vector<bool> visited(N+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    visited[0] = true;
    pq.push({ 1, 0 });
    long long int weight = 0;
    int cnt = 0;
    while (!pq.empty()) {
        int V = pq.top().first;
        long long int w = pq.top().second;
        pq.pop();
        if (visited[V]) continue;
        visited[V] = true;
        weight += w;
        cnt++;
        for (int i = 0; i < m[V].size(); i++) {
            pq.push({ m[V][i].first, m[V][i].second });
        }
    }
    if (cnt!=N)cout << -1;
    else cout << sum - weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sum = 0;
    int V, E;
    cin >> V >> E;
    N = V;
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < E; i++) {
        int r, c;
        cin >> r >> c;
        int value;
        cin >> value;
        m[r].push_back({ c, value });
        m[c].push_back({ r, value });
        sum += value;
    }

    func(m);
}