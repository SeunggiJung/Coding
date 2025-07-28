#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long int lli;
static int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        cin >> N >> M;
        if (!N && !M) break;
        vector<int> v(N);
        for (int i = 0; i < N; i++) cin >> v[i];
        vector<vector<lli>> dp(N, vector<lli>(N, 0));
        for (int i = 0; i < N; i++) dp[i][1] = 1;
        for (int i = 2; i <= M; i++) {
            for (int j = 1; j < N; j++) {
                for (int k = 0; k < j; k++) {
                    if (v[k] < v[j]) {
                        dp[j][i] += dp[k][i - 1];
                    }
                }
            }
        }
        lli sum = 0;
        for (int i = 0; i < N; i++)
            sum += dp[i][M];
        cout << sum << "\n";
    }
}