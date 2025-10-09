#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
vector<bool> primes(1121, true);
vector<vector<int>> dp(1121, vector<int>(15, 0));
int T, n, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    primes[0] = primes[1] = false;
    vector<int> p;
    for (int i = 2; i <= sqrt(1120); i++) {
        if (primes[i]) {
            for (int j = i * i; j <= 1120; j += i) {
                primes[j] = false;
            }
        }
    }

    dp[0][0] = 1; // dp[prime][1] = 1 만들기 용
    for (int i = 2; i <= 1120; i++) {
        if (!primes[i]) continue;
        for (int j = 1120; j >= i; j--) {
            for (int k = 1; k <= 14; k++) {
                dp[j][k] += dp[j - i][k - 1];
            }
        }
    }
    cin >> T;
    while (T-- > 0) {
        cin >> n >> k;
        if (k == 1) {
            cout << (primes[n] ? 1 : 0) << "\n";
            continue;
        }
        cout << dp[n][k] << "\n";
    }
}