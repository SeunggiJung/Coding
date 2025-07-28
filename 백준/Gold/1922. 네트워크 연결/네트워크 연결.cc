#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M;
static vector<int> v;
static vector<bool> visited;
static vector<bool> isprime;
static vector<int> out;
map<int, vector<pair<int, int>>> m;
static long long int min_value;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void mst() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({ 1,0 });
    int weight = 0;
    while (!pq.empty()) {
        int V = pq.top().first;
        int w = pq.top().second;
        pq.pop();
        if (v[V] == 1) continue;
        v[V] = 1;
        weight += w;
        for (int i = 0; i < m[V].size(); i++) {
            pq.push({ m[V][i].first,m[V][i].second });
        }
    }
    cout << weight;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<int>(N + 1);
    for (int i = 1; i < N + 1; i++) {
        v[i] = i;
    }
    v[1] = 0;
    for (int i = 0; i < M; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        m[parent].push_back({ child,weight });
        m[child].push_back({ parent,weight });
    }
    mst();
}
