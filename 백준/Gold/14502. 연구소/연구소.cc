#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, M;
vector<vector<int>> board;
vector<bool> visited;
queue<pii> q;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int maxi=0;
void bt(int depth,int index){
    if(depth==3){
        int cnt=0;
        vector<vector<int>> tmp = board;
        for(int i=0;i<N*M;i++){
            if(visited[i]){
                tmp[i/M][i%M] = 1;
            }
        }
        queue<pii> copy = q;
        while(!copy.empty()){
            int r = copy.front().first;
            int c = copy.front().second;
            copy.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0||nc<0||nr>=N||nc>=M) continue;
                if(tmp[nr][nc]) continue;
                tmp[nr][nc] = 2;
                copy.push({nr, nc});
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(tmp[i][j]==0){
                    cnt++;
                }
            }
        }
        maxi = max(maxi, cnt);
        return;
    }
    for(int i=index;i<N*M;i++){
        if(visited[i]) continue;
        if(board[i/M][i%M]) continue;
        visited[i] = true;
        bt(depth+1, index+1);
        visited[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.resize(N, vector<int>(M));
    visited.assign(N*M, false);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]==2){
                q.push({i,j});
            }
        }
    }
    bt(0,0);
    cout<<maxi;
}
