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
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
vector<vector<int>> board;
vector<vector<int>> dist;
int di(){
    dist[0][0] = board[0][0];
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({dist[0][0],0,0});
    while(!pq.empty()){
        int w = pq.top()[0];
        int r = pq.top()[1];
        int c = pq.top()[2];
        pq.pop();
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0||nc<0||nr>=N||nc>=N) continue;
            if(dist[nr][nc] > w + board[nr][nc]){
                dist[nr][nc] = w+board[nr][nc];
                pq.push({dist[nr][nc], nr, nc});
            }
        }
    }
    return dist[N-1][N-1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cnt = 0;
    while(true){
        cnt++;
        cin>>N;
        if(!N) break;
        board.assign(N, vector<int>(N));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>board[i][j];
            }
        }
        dist.assign(N, vector<int>(N, 999999));
        cout<<"Problem "<<cnt<<": "<<di()<<"\n";
    }
    
}