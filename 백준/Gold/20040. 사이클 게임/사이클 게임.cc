#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
static int N, M, K;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
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
    cin >> N >> M;
    parent = vector<int>(N);
    for (int i = 0; i < N; i++) parent[i] = i;
    bool flag = false;
    for(int i=1;i<=M;i++){
        int x, y;
        cin >> x >> y;
        if (parent[find(x)] == parent[find(y)]) {
            cout << i;
            return 0;
        }
        if (parent[find(x)] < parent[find(y)]) parent[find(y)] = parent[find(x)];
        else parent[find(x)] = parent[find(y)];
    }
    cout << 0;
}