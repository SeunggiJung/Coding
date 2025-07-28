#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<int> ledder(101, 0);
    vector<int> snake(101, 0);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        ledder[a] = b;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        snake[a] = b;
    }
    vector<bool> visited(101, false);
    queue<pii> q;
    q.push({ 1,0 });
    int mini = INT32_MAX;
    while (!q.empty()) {
        int node = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (node == 100) {
            mini = min(mini, cnt);
        }
        if (visited[node]||node>100) continue;
        visited[node] = true;
        for (int i = 1; i <= 6; i++) {
            int next = node + i;
            if (next > 100) continue;
            if (visited[next]) continue;
            if (snake[next]) {q.push({ snake[next], cnt + 1 });continue;}
            if (ledder[next]) {q.push({ ledder[next],cnt + 1 });continue;}
            q.push({ next, cnt + 1 });
        }
    }
    cout << mini;
}