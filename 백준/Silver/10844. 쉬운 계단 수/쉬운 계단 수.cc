#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int N, M;
map<char, int> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<vector<long long>> dp(101, vector<long long>(10,1));
    dp[1][0] = 0;
    for(int i=2;i<=N;i++){
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for(int j=1;j<9;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }
    long long sum = 0;
    for(int i=0;i<10;i++){
        sum += dp[N][i];
    }
    cout<<(sum%1000000000);
}