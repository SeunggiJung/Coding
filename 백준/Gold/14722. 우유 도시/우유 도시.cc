#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> dp;
vector<vector<int>> board;
int N;
int dr[] = {0,1};
int dc[] = {1,0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    dp.assign(N, vector<pii>(N, {0,-1})); // 개수, 마지막 마신 우유
    board.resize(N, vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    if(board[0][0]==0){
        dp[0][0] = {1, 0};
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!dp[i][j].first && board[i][j]) continue;
            if(!dp[i][j].first && !board[i][j])
                dp[i][j] = {1,0};
            for(int k=0;k<2;k++){
                int nr = i+dr[k];
                int nc = j+dc[k];
                if(nr>=N||nc>=N) continue;
                if(board[nr][nc]==(dp[i][j].second+1)%3){
                    if(dp[i][j].first+1 > dp[nr][nc].first){
                        dp[nr][nc] = {dp[i][j].first+1, board[nr][nc]};
                    }
                }
                else{
                    if(dp[i][j].first > dp[nr][nc].first){
                        dp[nr][nc] = dp[i][j];
                    }
                }
            }
        }
    }
    cout<<dp[N-1][N-1].first;
}