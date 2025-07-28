#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
static vector<int> v;
static int N, M;
void bt(vector<int> x, vector<bool> visited) {
    if (x.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << v[x[i]] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        x.push_back(i);
        visited[i] = true;
        bt(x, visited);
        visited[i] = false;
        x.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> x;
    vector<bool>visited(N, false);
    bt(x, visited);
}