#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<int> visited;
vector<int> trust;
map<int, vector<int>> m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    visited.resize(N+1, 0);
    trust.resize(N+1, -1);
    for(int i=1;i<=N;i++){
        int to;
        while(true){
            cin>>to;
            if(!to) break;
            m[i].push_back(to);
        }
    }
    cin>>M;
    queue<pii> q;
    for(int i=0;i<M;i++){
        int x;
        cin>>x;
        trust[x] = 0;
        q.push({x, 0});
    }
    while(!q.empty()){
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();
        for(int next : m[cur]){
            if(trust[next] != -1) continue;
            visited[next]++;
            if(visited[next] >= (m[next].size() + 1)/2){
                trust[next] = time+1;
                q.push({next, time+1});
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout<<trust[i]<<" ";
    }
}