#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, P, M;
bool comp(vector<int> v1, vector<int> v2) {
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    if (v1.empty()) return true;
    if (!v1.front()) return true;
    if (!v2.front()) return false;
    if (v1.front() && v1.size() > v2.size()) return false;
    if (v1.size() == v2.size() && v1 > v2) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> cost;
    for (int i = 0; i < N; i++) {
        cin >> P;
        cost.push_back(P);
    }
    cin >> M;
    vector<vector<int>> dp(M+1);
    for (int i = 0; i < M; i++) {
        for (int j = N-1; j >= 0; j--) {
            if (i + cost[j] <= M) {
                vector<int> n_d = dp[i];
                n_d.push_back(j);
                if (comp(dp[i + cost[j]], n_d)) {
                    dp[i + cost[j]] = n_d;
                }
            }
        }
    }
    sort(dp[M].rbegin(), dp[M].rend());
    if (!dp[M].front()) cout << 0;
    else for (int i : dp[M]) cout << i;
}