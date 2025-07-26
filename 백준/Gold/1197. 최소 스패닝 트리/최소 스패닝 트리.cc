#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

void func(map<int, vector<pair<int, int>>> m) {
    vector<bool> visited(m.size() + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({ 1, 0 });
    int weight = 0;
    while (!pq.empty()) {
        int check = 0;
        int V = pq.top().first;
        int w = pq.top().second;
        pq.pop();
        if (visited[V]) continue;
        visited[V] = true;
        weight += w;
        for (int i = 0; i < m[V].size(); i++) {
            pq.push({ m[V][i].first, m[V][i].second });
        }
    }
    cout << weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int V, E;
    cin >> V >> E;
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < E; i++) {
        int r, c;
        cin >> r >> c;
        int value;
        cin >> value;
        m[r].push_back({ c, value });
        m[c].push_back({ r, value });
    }
    
    func(m);
}