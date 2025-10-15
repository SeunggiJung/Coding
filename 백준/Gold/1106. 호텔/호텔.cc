#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int C, N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> C >> N;
    vector<int> dp(1101, 0); // index : 사람, value : 가격
    vector<pii> city(N);
    for (int i = 0; i < N; i++) {
        cin >> city[i].first >> city[i].second;
    }
    int mini = INT32_MAX;
    for (int i = 0; i < C; i++) {
        if (i != 0 && !dp[i]) continue;
        for (auto c : city) {
            int cost = c.first;
            int people = c.second;
            if(i+people>=C) mini = min(dp[i] + cost, mini);
            if (!dp[i + people]) dp[i + people] = dp[i] + cost;
            else {
                dp[i + people] = min(dp[i + people], dp[i] + cost);
            }
        }
    }
    cout << mini;
}

