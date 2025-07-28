#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;
int T, n, a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    vector<int> sum(501, 0);
    vector<vector<int>> dp(501, vector<int>(501, 0));
    for (int  t = 0; t < T; t++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            sum[i] = sum[i - 1] + a;
        }

        for (int k = 1; k < n; k++) {
            int i = 1;
            int j = k + 1;
            for (int u = 0; u < n - k; u++) {
                dp[i][j] = 1e9;
                for (int m = j - k; m <= j - 1; m++) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + sum[j] - sum[i - 1]);
                }
                i++;
                j++;
            }
        }
        cout << dp[1][n] << "\n";
    }
}