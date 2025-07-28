#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
static int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s1, s2;
    cin >> s1>> s2;
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1,0));
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    cout << dp[s1.length()][s2.length()];
}