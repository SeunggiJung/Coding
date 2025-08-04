#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N, K;
vector<int> dest;
vector<int> visited(100002,-1);
int bfs(int start, long long int time) {
    queue<pii> q;
    q.push({ start,0 });
    int ans = 0;
    while (!q.empty()) {
        int node = q.front().first;
        int t = q.front().second;
        int dr[] = { -1,1,node };
        q.pop();
        if (node == K) {
            ans = t;
            break;
        }
        for (int i = 0; i < 3; i++) {
            int nnode = node + dr[i];
            if (nnode < 0 || nnode>100001) continue;
            if (visited[nnode] != -1) continue;
            q.push({ nnode, t + 1 });
            visited[nnode] = i;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    cout << bfs(N, 0) << "\n";
    vector<int> route = { K };
    while (K != N) {
        if (visited[K] == 0) {
            K += 1;
        }
        else if (visited[K] == 1) {
            K -= 1;
        }
        else {
            K /= 2;
        }
        route.push_back(K);
    }
    while (!route.empty()) {
        cout << route.back() << " ";
        route.pop_back();
    }
}