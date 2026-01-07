#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef pair<int,int> pii;
vector<vector<int>> board;
vector<vector<bool>> visited;
int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
void bfs(pii start){
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0||nc<0||nr>=N||nc>=M) continue;
            if(visited[nr][nc]||!board[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}
int sector(){
    int cnt = 0;
    visited.assign(N, vector<bool>(M, false));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]) continue;
            if(board[i][j]){
                bfs({i,j});
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.resize(N, vector<int>(M));
    queue<pii> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]) q.push({i,j});
        }
    }
    int time = 0;
    while(true){
        int sec = sector();
        if(!sec){
            cout<<0;
            break;
        }
        if(sec>1){
            cout<<time;
            break;
        }
        vector<vector<int>> tmp = board;
        int qs = q.size();
        for(int i=0;i<qs;i++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int cnt = 0;
            for(int j=0;j<4;j++){
                int nr = r+dr[j];
                int nc = c+dc[j];
                if(!board[nr][nc]) cnt++;
            }
            tmp[r][c] = board[r][c] - cnt;
            if(tmp[r][c]<0) tmp[r][c] = 0;
            if(tmp[r][c]>0) q.push({r,c});
        }
        board = tmp;
        time++;
    }
}