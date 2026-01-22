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
int N, M;
vector<vector<char>> board(8, vector<char>(8));
vector<vector<bool>> visited(8, vector<bool>(8, false));
int dr[] = {1,-1,0,0,1,1,-1,-1};
int dc[] = {0,0,-1,1,1,-1,1,-1};
pii down(pii rc){
    int r = rc.first;
    int c = rc.second;
    board[r][c] = '.';
    int nr = r+1;
    if(nr==8) return {-1,-1};
    board[nr][c] = '#';
    return {nr, c};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string in;
    priority_queue<pii> pq;
    for(int i=0;i<8;i++){
        cin>>in;
        for(int j=0;j<8;j++){
            board[i][j] = in[j];
            if(in[j]=='#') pq.push({i,j});
        }
    }
    visited[7][0] = true;
    queue<pii> q;
    q.push({7,0});
    while(!q.empty()){
        int qs = q.size();
        visited.assign(8, vector<bool>(8, false));
        for(int k=0;k<qs;k++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r==0 && c==7) {
                cout<<1;
                return 0;
            }
            if(board[r][c]=='#') continue;
            for(int i=0;i<8;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0||nc<0||nr>7||nc>7) continue;
                if(visited[nr][nc]) continue;
                if(board[nr][nc]=='#') continue;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
            if(!visited[r][c]) {
                q.push({r, c});
                visited[r][c] = true;
            }
        }
        queue<pii> nq;
        while(!pq.empty()){
            pii next = down(pq.top());
            pq.pop();
            if(next.first==-1) continue;
            nq.push(next);
        }
        while(!nq.empty()){
            pq.push(nq.front());
            nq.pop();
        }
    }
    cout<<0;
}