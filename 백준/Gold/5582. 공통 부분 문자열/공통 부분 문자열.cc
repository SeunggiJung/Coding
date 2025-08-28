#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
string s1, s2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s1 >> s2;
    vector<vector<int>>dp(s1.length(), vector<int>(s2.length()));
    int ans = 0;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = 1;
                if (i && j) dp[i][j] += dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
}