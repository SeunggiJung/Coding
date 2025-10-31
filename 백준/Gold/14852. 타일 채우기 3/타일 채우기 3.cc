#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int N;
vector<vector<ll>> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    dp = vector<vector<ll>>(N + 1, vector<ll>(3, 0));
    int mod = 1000000007;

    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        // 꽉 채우는 경우
        dp[i][0] = dp[i-1][0]*2 + dp[i-1][1] + dp[i-1][2];
        if (i >= 2) dp[i][0] += dp[i-2][0];
        dp[i][0] %= mod;

        // 위
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;

        // 아래
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % mod;
    }
    cout << dp[N][0];
}