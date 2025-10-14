#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int N, b;
map<int, vector<int>> link;
int dfs(int node) {
    if (link.find(node) == link.end()) return 0;
    vector<int> child;
    for (int c : link[node]) {
        child.push_back(dfs(c));
    }
    sort(child.rbegin(), child.rend());
    int maxi = 0;
    for (int i = 0; i < child.size(); i++) {
        maxi = max(maxi, i + child[i] + 1);
    }
    return maxi;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b;
        if (b == -1) continue;
        link[b].push_back(i);
    }
    cout<<dfs(0);
}

