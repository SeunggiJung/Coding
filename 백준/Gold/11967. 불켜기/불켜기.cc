#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N,M;
map<pii, vector<pii>> m;
vector<vector<bool>> board;
vector<vector<bool>> visited;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.resize(N+1, vector<bool>(N+1, false));
    visited.resize(N+1, vector<bool>(N+1, false));
    board[1][1] = true;
    for(int i=0;i<M;i++){
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        m[{x,y}].push_back({a,b});
    }
    queue<pii> q;
    q.push({1,1});
    visited[1][1] = true;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(pii next : m[{r,c}]){
            board[next.first][next.second] = true;
            if(!visited[next.first][next.second]){
                bool flag=false;
                for(int i=0;i<4;i++){
                    int nr = next.first + dr[i];
                    int nc = next.second + dc[i];
                    if(nr<1||nc<1||nr>N||nc>N) continue;
                    if(visited[nr][nc]) flag=true;
                }
                if(flag) {
                    visited[next.first][next.second] = true;
                    q.push(next);
                }
            }
            
        }
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<1||nc<1||nr>N||nc>N) continue;
            if(visited[nr][nc]) continue;
            if(!board[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(board[i][j]) cnt++;
        }
    }
    cout<<cnt;
}