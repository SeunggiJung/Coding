#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.resize(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false)); // 0 : 가로, 1 : 세로
    vector<pii> acs;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]==9){
                acs.push_back({i,j});
                visited[i][j] = true;
            }
        }
    }
    for(auto& ac : acs){
        queue<vector<int>> q;
        for(int i=0;i<4;i++){
            q.push({ac.first, ac.second, i});
        }
        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            int d = q.front()[2];
            q.pop();
            visited[r][c] = true;
            if(d>1 && board[r][c]==1) continue;
            if(d<2 && board[r][c]==2) continue;
            if(board[r][c]==3) d=(d+2)%4;
            else if(board[r][c]==4) d=(3-d);
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr<0||nc<0||nr>=N||nc>=M) continue;
            if(board[nr][nc]==9) continue;
            q.push({nr, nc, d});
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]) cnt++;
        }
    }
    cout<<cnt;
}