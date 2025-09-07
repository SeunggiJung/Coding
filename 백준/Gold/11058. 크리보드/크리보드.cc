#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<long long> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    dp = vector<long long>(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 3; j < i; j++) {
            dp[i] = max(dp[i], dp[i - j] * (j - 1));
        }
    }
    cout << dp[N];
}