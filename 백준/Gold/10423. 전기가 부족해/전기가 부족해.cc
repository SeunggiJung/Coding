#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, M, K;
vector<int> gen;
vector<bool> visited;
map<int, vector<pii>> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M>>K;
    visited.assign(N+1, false);
    for(int i=0;i<K;i++){
        int g;
        cin>>g;
        gen.push_back(g);
    }
    for(int i=0;i<M;i++){
        int u, v, w;
        cin>>u>>v>>w;
        m[u].push_back({w, v});
        m[v].push_back({w, u});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int g : gen){
        pq.push({0, g});
    }
    int sum = 0;
    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        sum += weight;
        for(pii next : m[node]){
            if(visited[next.second]) continue;
            pq.push(next);
        }
    }
    cout<<sum;
}