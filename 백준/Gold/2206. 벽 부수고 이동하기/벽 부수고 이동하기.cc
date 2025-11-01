#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
vector<vector<int>> board;
vector<vector<vector<int>>> visited;
typedef pair<int, int> pii;
int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.assign(N, vector<int>(M));
    visited.assign(N, vector<vector<int>>(M, vector<int>(2, 1000001)));
    for(int i=0;i<N;i++){
        string line;
        cin>>line;
        for(int j=0;j<M;j++){
            board[i][j]=line[j]-'0';
        }
    }
    queue<pii> q;
    q.push({0,0});
    visited[0][0][0] = 1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(r==N-1 && c==M-1){
            cout<<min(visited[r][c][0], visited[r][c][1]);
            return 0;
        }
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0||nc<0||nr>=N||nc>=M) continue;
            if(board[nr][nc]==0){
                bool flag=false;
                if(visited[r][c][0]+1<visited[nr][nc][0]){
                    flag=true;
                    visited[nr][nc][0] = visited[r][c][0]+1;
                }
                if(visited[r][c][1]+1<visited[nr][nc][1]) {
                    flag=true;
                    visited[nr][nc][1] = visited[r][c][1]+1;
                }
                if(flag) q.push({nr,nc});
            }
            else{
                if(visited[r][c][0]+1<visited[nr][nc][1]){
                    visited[nr][nc][1] = visited[r][c][0]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
    cout<<-1;
}