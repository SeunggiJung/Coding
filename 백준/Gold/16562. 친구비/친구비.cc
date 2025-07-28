#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
static int N, M, K;
vector<int> p;
vector<int> fm;
int parent(int child) {
    if (p[child] == child) return child;
    return p[child] = parent(p[child]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> K;
    p.resize(N + 1);
    for (int i = 1; i <= N; i++) p[i] = i;
    fm.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> fm[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (fm[parent(a)] > fm[parent(b)]) p[parent(a)] = p[parent(b)];
        else p[parent(b)] = p[parent(a)];
    }
    vector<bool> visited(N + 1, false);
    int cost = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[p[parent(i)]]) {
            visited[p[parent(i)]] = true;
            cost += fm[p[parent(i)]];
            if (cost > K) {
                cout << "Oh no";
                return 0;
            }
        }
    }
    cout << cost;
}