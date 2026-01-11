#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef pair<double, int> pdi;
int N, M;
map<int, vector<pii>> m;
vector<vector<double>> dist;
vector<vector<bool>> visited;
void di(){
    int cur = 0;
    int goal = 1;
    dist[cur][0] = 0;
    priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> pq;
    pq.push({0, 0, 0});
    while(!pq.empty()){
        double w = pq.top()[0];
        cur = (int)pq.top()[1];
        int cnt = (int) pq.top()[2];
        pq.pop();
        if(visited[cur][cnt]) continue;
        visited[cur][cnt] = true;
        if(cur==goal) continue;
        for(auto& next : m[cur]){
            if(!visited[next.second][cnt]){
                dist[next.second][cnt] = min(dist[next.second][cnt], (double)next.first + w);
                pq.push({dist[next.second][cnt], (double) next.second, (double)cnt});
            }
            if(cnt<M && !visited[next.second][cnt+1]){
                dist[next.second][cnt+1] = min(dist[next.second][cnt+1], next.first/2.0 + w);
                pq.push({dist[next.second][cnt+1], (double) next.second, (double)cnt+1});
            }
        }
    }
    double res = INT_MAX;
    for(int i=0;i<=M;i++){
        res = min(res, dist[1][i]);
    }
    cout<<res;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    dist.assign(N, vector<double>(M+1, INT_MAX));
    visited.assign(N, vector<bool>(M+1, false));
    for(int i=0;i<N;i++){
        string in;
        cin>>in;
        for(int j=0;j<N;j++){
            m[i].push_back({in[j]-'0', j});
        }
    }
    di();

}
