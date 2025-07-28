#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
static int N, x;
static vector<vector<int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    v = vector<vector<int>>(N + 1);
    vector<int> preorder(N + 1, 0);
    vector<long long int> time(N + 1, 0);
    vector<long long int> mintime(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        time[i] = t;
        int pre;
        while (true) {
            cin >> pre;
            if (pre == -1) break;
            v[pre].push_back(i);
            preorder[i]++;
        }
    }
    queue<int> q;
    mintime = time;
    for (int i = 1; i <= N; i++) {
        if (preorder[i]==0) q.push(i);
    }
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j : v[i]) {
            mintime[j] = max(time[j]+mintime[i], mintime[j]);
            if (--preorder[j]==0) q.push(j);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << mintime[i] << "\n";
    }
}
