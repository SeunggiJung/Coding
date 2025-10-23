#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N,M,R;
int t,a,b,l;
int INF = 3001;
int ans=0;
vector<int> items;
vector<int> dist;
vector<bool> visited;
map<int, vector<pii>> m;
struct compare {
    bool operator()(const pair<int, long double>& a, const pair<int, long double>& b) {
        return a.second > b.second;
    }
};
void dijkstra(int start) {
    visited = vector<bool>(N + 1, false);
    dist = vector<int>(N + 1, INF);
    int cur = start;
    int w = 0;
    dist[cur] = 0;
    int res=0;
    priority_queue<pii, vector<pii>, compare> pq;
    pq.push({ cur,w });
    while (!pq.empty()) {
        w = pq.top().second;
        cur = pq.top().first;
        pq.pop();
        if (visited[cur])continue;
        res += items[cur];
        visited[cur] = true;
        for (auto& p : m[cur]) {
            if (visited[p.first])continue;
            if(w + p.second>M) continue;
            if (dist[p.first] > p.second + w) {
                dist[p.first] = p.second + w;
                pq.push({ p.first, dist[p.first] });
            }
        }
    }
    ans = max(res, ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M>>R;
    items.assign(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>items[i];
    }
    for(int i=0;i<R;i++){
        cin>>a>>b>>l;
        m[a].push_back({b,l});
        m[b].push_back({a,l});
    }
    for(int i=1;i<=N;i++){
        dijkstra(i);
    }
    cout<<ans;
}

