#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.assign(2, vector<int>(N));
    visited.assign(2, vector<bool>(N, false));
    int dc[] = {1, -1, M};
    string in;
    for(int i=0;i<2;i++){
        cin>>in;
        for(int j=0;j<N;j++){
            board[i][j] = in[j] - '0';
        }
    }
    queue<pii> q;
    q.push({0, 0});
    int cnt = 0;
    while(!q.empty()){
        int qs = q.size();
        visited.assign(2, vector<bool>(N, false));
        for(int i=0;i<qs;i++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(c < cnt) continue;
            if(visited[r][c]) continue;
            for(int j=0;j<2;j++){
                int nc = c + dc[j];
                if(nc>=N){
                    cout<<1;
                    exit(0);
                }
                if(nc<0||nc<cnt) continue;
                if(visited[r][nc]) continue;
                if(!board[r][nc]) continue;
                visited[r][nc] = true;
                q.push({r, nc});
            }
            int nr = r ? 0 : 1;
            int nc = c + dc[2];
            if(nc>=N){
                cout<<1;
                exit(0);
            }
            if(visited[nr][nc]) continue;
            if(!board[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
        cnt++;
    }
    cout<<0;
}