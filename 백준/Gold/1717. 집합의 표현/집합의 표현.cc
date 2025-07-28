#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
static int N, M;
vector<vector<int>> v;
int parent(int child) {
    if (v[child][0] == child) return child;
    else {
        v[child][0] = parent(v[child][0]);
        return v[child][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v=vector<vector<int>>(N + 1);
    queue<string> q;
    for (int i = 0; i < N + 1; i++) {
        v[i] = { i };
    }
    for (int i = 0; i < M; i++) {
        int ys, a, b;
        cin >> ys >> a >> b;
        if (ys) {
            if (parent(a) == parent(b)) {
                q.push("YES\n");
            }
            else {
                q.push("NO\n");
            }
        }
        else {
            v[parent(b)][0] = v[parent(a)][0];
        }
    }
    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }
}