#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<int> v;
vector<int> visited;
vector<int> ans;
int N;
void dfs(int start, int cur){
    visited[cur] = start;
    if(visited[v[cur]] == start){
        int cnt=0;
        int X = v[cur];
        while(true){
            ans.push_back(X);
            visited[X] = true;
            X = v[X];
            if(X==v[cur]) break;
        }
        return;
    }
    if(visited[v[cur]]) return;
    dfs(start, v[cur]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    v.resize(N+1);
    visited.assign(N+1, false);
    for(int i=1;i<=N;i++){
        cin>>v[i];
    }
    for(int i=1;i<=N;i++){
        if(visited[i]) continue;
        dfs(i, i);
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int i : ans){
        cout<<i<<"\n";
    }
}