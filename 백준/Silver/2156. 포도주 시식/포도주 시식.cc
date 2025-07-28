#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    if (N == 1) {
        cout << v[0]; return 0;
    }
    else if (N == 2) {
        cout << v[0] + v[1]; return 0;
    }
    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++) dp[i] = v[i];
    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = max(max(v[0], v[1]) + v[2], dp[1]);
    for (int i = 3; i < N; i++) {
        if (!v[i]) { dp[i] = dp[i - 1]; continue; }
        dp[i] = max(max(v[i - 1] + dp[i - 3], dp[i - 2]) + v[i], dp[i - 1]);
    }
    cout << dp[N - 1];
}
