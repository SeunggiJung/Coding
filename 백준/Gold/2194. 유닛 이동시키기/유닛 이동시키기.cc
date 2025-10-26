#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int N,M,A,B,K;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M>>A>>B>>K;
    vector<vector<int>> board(N+1, vector<int>(M+1,0));
    vector<vector<bool>> visited(N+1, vector<bool>(M+1,false));
    for(int i=0;i<K;i++){
        int x,y;
        cin>>x>>y;
        board[x][y] = -1;
    }
    pii start, end;
    cin>>start.first>>start.second;
    cin>>end.first>>end.second;
    queue<pii> q;
    q.push(start);
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        if(cr==end.first&&cc==end.second) break;
        if(visited[cr][cc]) continue;
        visited[cr][cc] = true;
        for(int i=0;i<4;i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr<=0||nc<=0||nr+A-1>N|nc+B-1>M) continue;
            if(visited[nr][nc]) continue;
            
            bool flag=true;
            for(int j=0;j<A;j++){
                if(board[nr+j][nc]==-1 || board[nr+j][nc+B-1]==-1){
                    flag=false;
                    break;
                }
            }
            for(int j=0;j<B;j++){
                if(board[nr][nc+j]==-1 || board[nr+A-1][nc+j]==-1){
                    flag=false;
                    break;
                }
            }
            if(flag){
                board[nr][nc] = board[cr][cc] + 1;
                q.push({nr,nc});
            }
        }
    }
    if(board[end.first][end.second]==0){
        cout<<-1<<"\n";
    }
    else
        cout<<board[end.first][end.second];
}