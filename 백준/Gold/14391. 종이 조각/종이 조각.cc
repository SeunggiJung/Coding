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
int dr[] = {1,0};
int dc[] = {0,1};
int maxi = 0;
int tonum(pii s, int d, int len){
    int res = 0;
    pii cur = s;
    for(int i=1;i<=len;i++){
        res+=board[cur.first][cur.second] * pow(10, len-i);
        visited[cur.first][cur.second] = true;
        cur.first += dr[d];
        cur.second+= dc[d];
    }
    return res;
}
void solve(int index, int sum){
    vector<vector<bool>> origin = visited;
    int r = index / M;
    int c = index % M;
    for(int i = 0;r + i<N;i++){
        if(visited[r+i][c]) break;
        int nsum = sum + tonum({r,c}, 0, i+1);
        maxi = max(maxi, nsum);
        for(int j=index+1;j<N*M;j++){
            if(board[j/M][j%M] && !visited[j/M][j%M]){
                solve(j, nsum);
                break;
            }
        }
        visited = origin;
    }
    for(int i = 0;c + i<M;i++){
        if(visited[r][c+i]) break;
        int nsum = sum + tonum({r,c}, 1, i+1);
        maxi = max(maxi, nsum);
        for(int j=index+1;j<N*M;j++){
            if(board[j/M][j%M] && !visited[j/M][j%M]){
                solve(j, nsum);
                break;
            }
        }
        visited = origin;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.resize(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));
    string in;
    for(int i=0;i<N;i++){
        cin>>in;
        for(int j=0;j<M;j++){
            board[i][j] = in[j] - '0';
        }
    }
    solve(0, 0);
    cout<<maxi;
}