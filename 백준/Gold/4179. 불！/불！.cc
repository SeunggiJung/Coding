#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    vector<vector<char>> board(N, vector<char>(M));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<vector<int>> q;
    pii jihoon;
    vector<pii> fire;
    for(int i=0;i<N;i++){
        string in;
        cin>>in;
        for(int j=0;j<M;j++){
            board[i][j] = in[j];
            if(board[i][j] == 'J') jihoon = {i,j};
            if(board[i][j] == 'F') fire.push_back({i,j});
        }
    }
    visited[jihoon.first][jihoon.second] = 1;
    for(pii x : fire) q.push({x.first, x.second, 1});
    q.push({jihoon.first, jihoon.second, 0});
    while(!q.empty()){
        int r = q.front()[0];
        int c = q.front()[1];
        char who = q.front()[2]==0 ? 'J' : 'F';
        q.pop();
        if(who=='J'){
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0||nc<0||nr>=N||nc>=M){
                    cout<<visited[r][c];
                    return 0;
                }
                if(visited[nr][nc]) continue;
                if(board[nr][nc]=='#'||board[nr][nc]=='F') continue;
                visited[nr][nc] = visited[r][c] + 1;
                q.push({nr,nc,0});
            }
        }
        if(who=='F'){
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0||nc<0||nr>=N||nc>=M) continue;
                if(board[nr][nc]=='#'||board[nr][nc]=='F') continue;
                board[nr][nc] = 'F';
                q.push({nr,nc,1});
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}
