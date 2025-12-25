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
int N;
vector<vector<int>> board;
void dfs(int start){
    vector<bool> visited(N, false);
    queue<int> q;
    for(int i=0;i<N;i++){
        if(board[start][i]) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        board[start][node] = 1;
        visited[node] = true;
        for(int i=0;i<N;i++){
            if(visited[i]) continue;
            if(board[node][i]) q.push(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    board.resize(N, vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<N;i++){
        dfs(i);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}