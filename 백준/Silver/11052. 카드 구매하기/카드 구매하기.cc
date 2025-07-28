#include <iostream>
#include <vector>

using namespace std;
static int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N+1);
    for (int i = 1;i <= N;i++) cin >> v[i];
    vector<int> dp(N+1);
    dp[1] = v[1];
    dp[2] = max(v[2], dp[1] * 2);
    int res = 0;
    for (int i = 3;i <= N;i++) {
        dp[i] = v[i];
        for (int j = 1;j < i;j++) {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
        res = max(res, dp[i]);
    }
    cout << dp[N];
}