#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
static int N, M, L;
map<int, vector<pii>> m;
int maxi = 0;
int far;
vector<bool> visited;
void dfs(int last, int sum) {
    if (sum > maxi) {
        far = last;
        maxi = sum;
    }
    visited[last] = true;
    for (int i = 0; i < m[last].size(); i++) {
        int next = m[last][i].first;
        int weight = m[last][i].second;
        if (visited[next]) continue;
        dfs(next, sum + weight);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> N >> M >> L) {
        m[N].push_back(make_pair(M, L));
        m[M].push_back(make_pair(N, L));
    }
    visited = vector<bool>(10001, false);
    dfs(1, 0);
    visited = vector<bool>(10001, false);
    dfs(far, 0);
    cout << maxi;
}