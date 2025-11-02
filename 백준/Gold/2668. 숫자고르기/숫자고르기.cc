#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<int> v;
vector<bool> visited;
vector<bool> finish;
int N;
vector<int> ans;
int maxi=0;
void dfs(int cur, vector<int> route){
    visited[cur] = true;
    route.push_back(cur);
    int next = v[cur];
    if(visited[next]){
        if(!finish[next]){
            for(int i=0;i<route.size();i++){
                if(route[i]==next){
                    for(int j=i;j<route.size();j++) 
                        ans.push_back(route[j]);
                    break;
                }
            }
        }
    }
    else{
        dfs(next, route);
    }
    finish[cur] = true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    v.resize(N+1);
    visited.resize(N+1, false);
    finish.resize(N+1, false);
    for(int i=1;i<=N;i++){
        cin>>v[i];
    }
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            dfs(i, {});
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int i : ans){
        cout<<i<<"\n";
    }
}