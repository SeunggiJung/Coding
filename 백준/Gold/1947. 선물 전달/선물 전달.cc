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
    vector<long long int> dp(1000001, 1);
    dp[1] = 0;
    dp[3] = 2;
    for (int i = 4; i <= N; i++) {
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % 1000000000;
    }
    cout << dp[N];
}