#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, M;
map<int, vector<pii>> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        m[a].push_back({b,c});
        m[b].push_back({a,c});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(N+1, false);
    int sum=0;
    pq.push({0,1});
    int maxi=0;
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        sum+=cost;
        maxi = max(maxi, cost);
        for(pii next : m[node]){
            if(visited[next.first]) continue;
            pq.push({next.second, next.first});
        }
    }
    cout<<sum - maxi;
}
