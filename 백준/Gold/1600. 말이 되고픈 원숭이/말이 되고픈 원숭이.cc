#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <sstream>
using namespace std;
typedef pair<int,int> pii;
int K, N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int hr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hc[] = {1, 2, 2, 1, -1, -2, -2, -1};
vector<vector<int>> board;
vector<vector<vector<int>>> visited;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>K>>M>>N;
    board.resize(N, vector<int>(M));
    visited.assign(K+1, vector<vector<int>>(N, vector<int>(M, 0)));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    queue<vector<int>> q;
    q.push({0,0,0});
    visited[0][0][0] = 0;
    while(!q.empty()){
        int r = q.front()[0];
        int c = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        if(r==N-1&&c==M-1){
            cout<<visited[cnt][r][c]<<"\n";
            return 0;
        }
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<0||nc<0||nr>=N||nc>=M) continue;
            if(visited[cnt][nr][nc]) continue;
            if(board[nr][nc]) continue;
            q.push({nr,nc,cnt});
            visited[cnt][nr][nc] = visited[cnt][r][c] + 1;
        }
        if(cnt>=K) continue;
        for(int i=0;i<8;i++){
            int nr = r+hr[i];
            int nc = c+hc[i];
            if(nr<0||nc<0||nr>=N||nc>=M) continue;
            if(visited[cnt+1][nr][nc]) continue;
            if(board[nr][nc]) continue;
            q.push({nr, nc, cnt+1});
            visited[cnt+1][nr][nc] = visited[cnt][r][c] + 1;
        }
    }
    cout<<-1;
}
