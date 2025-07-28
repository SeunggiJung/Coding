#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;
int N, M;
double INF = 1000;
vector<double> dist;
map<int, vector<pair<int, int>>> m;
pair<double, double> start, goal;
vector<bool> visited;
vector<pair<double, double>> v;
struct compare {
    bool operator()(const pair<int, double>& a, const pair<int, double>& b) {
        return a.second > b.second;
    }
};
double calc_dist(pair<double, double> p1, pair<double,double> p2) {
    return sqrtf(powf(p1.first - p2.first, 2) + powf(p1.second - p2.second, 2));
}
void dijkstra() {
    priority_queue<pair<int, double>, vector<pair<int, double>>, compare> pq;
    pq.push({ 0,0 });
    while (!pq.empty()) {
        int cur = pq.top().first;
        double cost = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) continue;
        for (int i = 0; i <= N+1; i++) {
            double length = calc_dist(v[cur], v[i]);
            double walk = length / 5;
            double canon = 2 + fabs(length - 50) / 5;
            double mini;
            if (cur==0) { mini = walk;}
            else mini = min(walk, canon);
            if (mini + cost < dist[i]) {
                dist[i] = mini + cost;
                pq.push({ i,dist[i] });
            }
        }
    }
    cout << dist[N+1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> start.first >> start.second;
    cin >> goal.first >> goal.second;
    v.push_back(start);
    cin >> N;
    for (int i = 0; i < N; i++) {
        double a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }
    v.push_back(goal);
    dist = vector<double>(N+2, INF);
    dist[0] = 0;
    dijkstra();
}