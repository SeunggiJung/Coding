#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int, int> pii; 
int N, M;
vector<pii> v;
vector<bool> visited;
map<pii, bool> linked;
struct compare {
    bool operator()(const pair<int, long double>& a, const pair<int, long double>& b) {
        return a.second > b.second;
    }
};
long double calc_dist(pii p1, pii p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
void mst() {
    priority_queue<pair<int, long double>, vector<pair<int, long double>>, compare> pq;
    pq.push({ 1,0 });
    long double weight = 0;
    int cur;
    long double w;
    while (!pq.empty()) {
        cur = pq.top().first;
        w = pq.top().second;
        pq.pop();
        if (visited[cur]) continue;
        weight += w;
        visited[cur] = true;
        for (int next = 1; next <= N; next++) {
            if (linked[{cur, next}] || linked[{next, cur}]) {
                pq.push({ next, 0 });
                continue;
            }
            if (next == cur || visited[next]) continue;
            pq.push({ next, calc_dist(v[cur], v[next])});
        }
    }
    printf("%.2Lf", weight);
    //cout << weight;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<pii>(N+1);
    visited = vector<bool>(N+1, false);
    for (int i = 1; i <= N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        linked[{a, b}] = true;
        linked[{b, a}] = true;
    }
    mst();
}
