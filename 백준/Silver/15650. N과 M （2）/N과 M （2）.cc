#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
int N, M, T;
void bt(int depth, int last) {
    if (depth == M) {
        for (int i = 1; i <= N; i++) {
            if (visited[i]) cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = last+1; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        bt(depth + 1,i);
        visited[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    visited = vector<bool>(N + 1, false);
    bt(0, 0);
}