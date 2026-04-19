#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<vector<int>> dp;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};

int dfs(int r, int c){
    if(r<0||c<0||r>=N||c>=M || !board[r][c]) return 0;

    if(visited[r][c]) {
        cout<<-1;
        exit(0);
    }
    if(dp[r][c] != -1) return dp[r][c];
    
    visited[r][c] = true;
    dp[r][c] = 0;
    for(int i=0;i<4;i++){
        int nr = r + dr[i] * board[r][c];
        int nc = c + dc[i] * board[r][c];
        dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1);
    }
    visited[r][c] = false;
    return dp[r][c];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    board.assign(N,vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));
    dp.assign(N, vector<int>(M, -1));
    for(int i=0;i<N;i++){
        string in;
        cin>>in;
        for(int j=0;j<M;j++){
            if(in[j]=='H') board[i][j] = 0;
            else board[i][j] = in[j] - '0';
        }
    }
    cout<<dfs(0, 0);
}