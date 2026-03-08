#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int N, M;
pii st, en;
vector<vector<int>> board;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    cin>>st.first>>st.second;
    cin>>en.first>>en.second;
    board.assign(N+1, vector<int>(M+1, -1));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
        }
    }
    vector<vector<vector<int>>> visited(N+1, vector<vector<int>>(M+1, vector<int>(2, 0)));
    queue<vector<int>> q;
    q.push({st.first, st.second, 0});
    while(!q.empty()){
        int r = q.front()[0];
        int c = q.front()[1];
        int b = q.front()[2];
        q.pop();
        if(r==en.first && c==en.second) break;
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<=0||nc<=0||nr>N||nc>M) continue;
            if(board[nr][nc]){
                if(b) continue;
                if(visited[nr][nc][1]) continue;
                visited[nr][nc][1] = visited[r][c][b] + 1;
                q.push({nr, nc, 1});
            }
            else{
                if(visited[nr][nc][b]) continue;
                visited[nr][nc][b] = visited[r][c][b] + 1;
                q.push({nr, nc, b});
            }
        }
    }
    int res = N*M+1;
    if(visited[en.first][en.second][0]) res = min(res, visited[en.first][en.second][0]);
    if(visited[en.first][en.second][1]) res = min(res, visited[en.first][en.second][1]);
    if(res == N*M+1) cout<<-1;
    else cout<<res;
}
