#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> dp(50001, 0);
    int x = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    while (x * x <= 50000) {
        int p = x * x;
        dp[p] = 1;
        for (int i = 1; i <= p*2; i++) {
            if (!dp[i]) continue;
            if (p + i > 50000) break;
            if (!dp[p + i]) dp[p + i] = dp[p] + dp[i];
            else dp[p + i] = min(dp[p + i], dp[p] + dp[i]);
        }
        x++;
    }
    //cout << count(dp.begin(), dp.end(), 5) << "\n";
    cout << dp[N];
}