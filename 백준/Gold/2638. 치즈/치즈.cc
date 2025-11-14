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
vector<vector<int>> board;
vector<vector<bool>> ext;
void find_ext(){
    queue<pii> q;
    q.push({0,0});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(ext[r][c]) continue;
        ext[r][c] = true;
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0||nc<0||nr>=N||nc>=M) continue;
            if(board[nr][nc]) continue;
            q.push({nr,nc});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.resize(N, vector<int>(M));
    ext.resize(N, vector<bool>(M, false));
    queue<pii> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]) q.push({i,j});
        }
    }
    int qs;
    int time=0;
    while(!q.empty()){
        time++;
        qs = q.size();
        vector<pii> del;
        ext.assign(N, vector<bool>(M, false));
        find_ext();
        for(int i=0;i<qs;i++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int cnt=0;
            for(int j=0;j<4;j++){
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(board[nr][nc]==0 && ext[nr][nc]){
                    cnt++;
                    continue;
                }
            }
            if(cnt>=2){
                del.push_back({r,c});
                continue;
            }
            q.push({r, c});
        }
        for(auto &x : del){
            board[x.first][x.second] = 0;
        }
        
    }
    cout<<time;
}
