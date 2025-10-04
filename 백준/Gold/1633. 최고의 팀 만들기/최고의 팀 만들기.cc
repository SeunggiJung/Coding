#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<pii> bw;
vector<vector<vector<int>>> dp; // i=index, j=black, k=white
int dfs(int index, int b_cnt, int w_cnt) {
    if (index == bw.size()) return 0;
    if (b_cnt == 15 && w_cnt == 15) return 0;

    if (dp[index][b_cnt][w_cnt]) return dp[index][b_cnt][w_cnt];

    dp[index][b_cnt][w_cnt] = max(dp[index][b_cnt][w_cnt], dfs(index + 1, b_cnt, w_cnt));

    if(b_cnt<15)
        dp[index][b_cnt][w_cnt] = max(dp[index][b_cnt][w_cnt], dfs(index + 1, b_cnt+1, w_cnt) + bw[index].first);

    if (w_cnt < 15)
        dp[index][b_cnt][w_cnt] = max(dp[index][b_cnt][w_cnt], dfs(index + 1, b_cnt, w_cnt + 1) + bw[index].second);

    return dp[index][b_cnt][w_cnt];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int black, white;
    while (cin >> black >> white) {
        bw.push_back({ black, white });
    }
    dp = vector<vector<vector<int>>>(1001, vector<vector<int>> (16, vector<int>(16, 0)));
    cout<<dfs(0, 0, 0);
}
