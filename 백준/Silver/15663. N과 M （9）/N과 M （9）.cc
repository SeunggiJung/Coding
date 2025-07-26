#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
static int N, M, T;
map<vector<int>, bool> outed;
map<int, bool> visited;
vector<int> v;
void bt(int depth, int index, vector<int> pw) {
    if (depth == M) {
        if (outed[pw]) return;
        outed[pw] = true;
        for (int i = 0; i < depth; i++) {
            cout << pw[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        pw.push_back(v[i]);
        bt(depth + 1, i + 1, pw);
        pw.pop_back();
        visited[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    bt(0, 0, vector<int>());
}