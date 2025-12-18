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
int INF = 2501;
int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
vector<vector<int>> board;
int bfs(vector<pii> active){
    vector<vector<int>> visited(N, vector<int>(N, 0));
    queue<pii> q;
    for(auto& v : active){
        q.push(v);
        visited[v.first][v.second] = 1;
    }
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0||nc<0||nr>=N||nc>=N) continue;
            if(visited[nr][nc]) continue;
            if(board[nr][nc]==1) continue;
            visited[nr][nc] = visited[r][c] + 1;
            q.push({nr, nc});
        }
    }
    int maxi = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0){
                if(!visited[i][j]) return INF;
                maxi = max(maxi, visited[i][j] - 1);
            }
        }
    }
    return maxi;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.resize(N, vector<int>(N));
    vector<pii> virus;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]==2) virus.push_back({i,j});
        }
    }
    int mini = INF;
    for(int i=(1<<M-1);i<(1<<virus.size());i++){
        vector<pii> v;
        int cnt = 0;
        for(int j=0;j<virus.size();j++){
            if(1<<j & i){
                cnt++;
                v.push_back({virus[j]});
            }
        }
        if(cnt==M) mini = min(mini, bfs(v));
    }
    if(mini == INF) cout<<-1;
    else cout<<mini;
}