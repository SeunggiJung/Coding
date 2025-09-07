#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N, M;
map<int, vector<int>> m;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second < b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<int> dp(N + 1, 1);
    vector<int> height(N + 1);
    priority_queue<pii, vector<pii>, compare> pq;
    for (int i = 1; i <= N; i++) {
        cin >> height[i];
        pq.push({ i, height[i] });
    }
    for (int i = 1; i <= M; i++) {
        int from, to;
        cin >> from >> to;
        if (height[from] < height[to]) m[from].push_back({ to });
        if (height[from] > height[to]) m[to].push_back({ from });
    }
    while (!pq.empty()) {
        int node = pq.top().first;
        int h = pq.top().second;
        pq.pop();
        if (m[node].size()) {
            for (auto& a : m[node]) {
                if(height[a]>h) dp[node] = max(dp[a]+1, dp[node]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << "\n";
    }
}