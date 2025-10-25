#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int w,h;
vector<vector<vector<int>>> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>w>>h;
    dp = vector<vector<vector<int>>>(h+1, vector<vector<int>>(w+1, vector<int>(2,0))); // 세로 : 0, 가로 : 1
    dp[2][1][0] = 1;
    dp[1][2][1] = 1;
    dp[2][2][0] = 1;
    dp[2][2][1] = 1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j-1][1];
            dp[i][j][0] %= 100000;
            dp[i][j][1] += dp[i-1][j-1][0] + dp[i][j-1][1];
            dp[i][j][1] %= 100000;
        }
    }
    cout<<(dp[h][w][0] + dp[h][w][1])%100000<<"\n";
}

