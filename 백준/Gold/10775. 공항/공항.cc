#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
static int N, M;
vector<int> parent;
int find(int child) {
    if (parent[child] == child)
        return child;
    return parent[child] = find(parent[child]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int G, P, gi;
    cin >> G >> P;
    parent.resize(G + 1);
    for (int i = 0; i <= G; i++) {
        parent[i] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= P; i++) {
        cin >> gi;
        gi = find(gi);
        if (gi == 0) break;
        parent[gi] = gi - 1;
        cnt++;
    }
    cout << cnt;
}