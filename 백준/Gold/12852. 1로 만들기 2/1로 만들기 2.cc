#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<pair<int, int>> dp(1000001);
    for (int i = 1; i <= 1000000; i++) {
        dp[i].first = 1000001;
    }
    dp[1].first = 0;
    for (int i = 1; i < 1000000; i++) {
        if (i+1<=1000000&&dp[i + 1].first > dp[i].first) {
            dp[i + 1].first = dp[i].first + 1;
            dp[i + 1].second = i;
        }
        if (i*2<= 1000000&&dp[i*2].first > dp[i].first) {
            dp[i * 2].first = dp[i].first + 1;
            dp[i * 2].second = i;
        }
        if (i*3<= 1000000&&dp[i*3].first > dp[i].first) {
            dp[i * 3].first = dp[i].first + 1;
            dp[i * 3].second = i;
        }
    }
    cout << dp[N].first << "\n";
    int index = N;
    while (index >= 1) {
        cout << index << " ";
        index = dp[index].second;
    }
}