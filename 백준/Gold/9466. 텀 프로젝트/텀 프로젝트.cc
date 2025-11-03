#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<int> v;
vector<int> visited;
int T,N,ans;
void dfs(int start, int cur){
    visited[cur] = start;
    if(visited[v[cur]] == start){
        int X = v[cur];
        while(true){
            ans--;
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
    cin>>T;
    while(T-->0){
        cin>>N;
        v.resize(N+1);
        visited.assign(N+1, false);
        ans = N;
        for(int i=1;i<=N;i++){
            cin>>v[i];
        }
        for(int i=1;i<=N;i++){
            if(visited[i]) continue;
            dfs(i, i);
        }
        cout<<ans<<"\n";
    }

}