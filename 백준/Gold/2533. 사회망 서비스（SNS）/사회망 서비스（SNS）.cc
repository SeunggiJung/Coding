#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> link;
vector<bool> visited;
vector<vector<int>> dp;
int N, M;
void func(int from) {
    visited[from] = true;
    dp[from][1] = 1;
    for (int i = 0; i < link[from].size(); i++) {
        int to = link[from][i];
        if (!visited[to]) {
            func(to);
            dp[from][0] += dp[to][1];
            dp[from][1] += min(dp[to][0], dp[to][1]);
            // 부모가 0이면 자식은 무조건 1, 부모가 1이면 자식은 0, 1 둘 다 가능
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    dp = vector<vector<int>>(N + 1, vector<int>(2, 0)); // 0 : 일반, 1 : 얼리
    visited = vector<bool>(N + 1, false);
    link = vector<vector<int>>(N + 1);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    func(1);
    cout << min(dp[1][0], dp[1][1]);
}