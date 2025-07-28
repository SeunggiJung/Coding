#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M, T;
vector<bool> visited;
vector<pair<int, int>> ans;
void bt(vector<int> v) {
    if (v.size() == M) {
        for (auto& a : v) {
            cout << a + 1 << " ";
        }
        cout << "\n";
        return;
    }
    int start = 0;
    if (v.size()) start = v.back();
    for (int i = start; i < N; i++) {
        v.push_back(i);
        bt(v);
        v.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    visited = vector<bool>(N, false);
    vector<int> v;
    bt(v);
}