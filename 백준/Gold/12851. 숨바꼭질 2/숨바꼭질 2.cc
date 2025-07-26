#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
static int N, K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    vector<int> time(100001, INT32_MAX);
    queue<pii> q;
    q.push({ N,0 });
    time[N] = 0;
    int cnt = 0;
    int mini = INT32_MAX;
    while (!q.empty()) {
        int node = q.front().first;
        int t = q.front().second;
        q.pop();
        if (node > 100000 || node < 0 || t>mini) continue;
        if (time[node] < t) continue;
        time[node] = t;
        if (node == K) {
            mini = min(mini, t);
            cnt += 1;
            continue;
        }
        q.push({ node - 1, t + 1 });
        q.push({ node + 1, t + 1 });
        q.push({ node * 2, t + 1 });
    }
    cout << mini << "\n" << cnt;
}