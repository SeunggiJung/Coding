#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int INF = 99999999;
vector<vector<int>> v;
vector<bool> visited;
map<pii, bool> linked;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N; 
    v.assign(N, vector<int>(N));
    visited.assign(N, false);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int sum=0;
    int minus=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>v[i][j];
            if(v[i][j]<0) minus+=v[i][j];
        }
    }
    int cnt=0;
    vector<pii> link;
    pq.push({0,0,1});
    while(!pq.empty()){
        int w = pq.top()[0];
        int pre = pq.top()[1];
        int cur = pq.top()[2];
        pq.pop();
        if(visited[cur]) continue;
        visited[cur]=true;
        if(w>0){
            sum+=abs(w);
            cnt++;
            link.push_back({pre, cur});
        }
        for(int i=0;i<N;i++){
            if(v[cur][i]==0) continue;
            pq.push({v[cur][i], cur, i});
        }
    }
    sum-=(minus/2);
    cout<<sum<<" "<<cnt<<"\n";
    for(auto& pc : link){
        cout<<pc.first+1<<" "<<pc.second+1<<"\n";
    }
}