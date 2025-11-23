#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N,M,H;
vector<vector<int>> linked;
vector<vector<bool>> visited;
int mini=INT_MAX;
bool flag=false;
bool check(){
    for(int i=1;i<=N;i++){
        int cur = i;
        for(int j=1;j<=H;j++){
            cur = linked[cur][j];
        }
        if(cur!=i) return false;
    }
    return true;
}
void bt(int depth, int bef, int goal){
    if(flag) return;
    if(depth==goal){
        if(check()) flag=true;
        return;
    }
    for(int i=bef;i<N*H;i++){
        int h = i/N + 1;
        int n = i%N + 1;
        if(n==N) continue;
        if(visited[n][h]||visited[n+1][h]) continue;
            vector<vector<int>> tmp = linked;
            visited[n][h] = true;
            visited[n+1][h] = true;
            linked[n][h] = n+1;
            linked[n+1][h] = n;
            bt(depth+1, i + 1, goal);
            linked = tmp;
            visited[n][h] = false;
            visited[n+1][h] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M>>H;
    linked.resize(N+1, vector<int>(H+1));
    visited.assign(N+1, vector<bool>(H+1, false));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=H;j++){
            linked[i][j] = i;
        }
    }
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        linked[b][a] = b+1;
        linked[b+1][a] = b;
        visited[b][a] = true;
        visited[b+1][a] = true;
    }
    if(check()){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=3;i++){
        bt(0, 0, i);
        if(flag) {cout<<i; return 0;}
    }
    cout<<-1;
}   