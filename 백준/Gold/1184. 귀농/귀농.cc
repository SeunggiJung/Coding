#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N;
vector<vector<int>> board;
vector<vector<int>> dp;
map<int, int> m1;
map<int, int> m2;
void check_ur(int r, int c){
    int fr, fc;
    int cnt = 0;
    for(fr=r-1;fr>0;fr--){
        for(fc=c+1;fc<=N;fc++){
            int tmp = dp[r-1][fc] - dp[r-1][c] - dp[fr-1][fc] + dp[fr-1][c];
            if(!m1[tmp]) m1[tmp]=0;
            m1[tmp]++;
        }
    }
}
void check_ul(int r, int c){
    int fr, fc;
    int cnt = 0;
    for(fr=r-1;fr>0;fr--){
        for(fc=c-1;fc>0;fc--){
            int tmp = dp[r-1][c-1] - dp[fr-1][c-1] - dp[r-1][fc-1] + dp[fr-1][fc-1];
            if(!m2[tmp]) m2[tmp] = 0;
            m2[tmp]++;
        }
    }
}
int check_dr(int r, int c){
    int fr, fc;
    int cnt = 0;
    for(fr=r+1;fr<=N;fr++){
        for(fc=c+1;fc<=N;fc++){
            int tmp = dp[fr][fc] - dp[fr][c] - dp[r][fc] + dp[r][c];
            if(m2.count(tmp)) cnt+=m2[tmp];
        }
    }
    return cnt;
}
int check_dl(int r, int c){
    int fr, fc;
    int cnt = 0;
    for(fr=r+1;fr<=N;fr++){
        for(fc=c-1;fc>0;fc--){
            int tmp = dp[fr][c-1] - dp[fr][fc-1] - dp[r][c-1] + dp[r][fc-1];
            if(m1.count(tmp)) cnt+=m1[tmp];
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    board.assign(N+1, vector<int>(N+1));
    dp.assign(N+1, vector<int>(N+1,0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + board[i][j];
        }
    }
    int cnt = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            m1.clear();
            m2.clear();
            check_ur(i,j);
            check_ul(i,j);
            cnt+=check_dr(i-1,j-1);
            cnt+=check_dl(i-1,j+1);
        }
    }
    cout<<cnt;
}