#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M;
static vector<vector<int>> v;
static vector<bool> visited;
static vector<int> miv;
static vector<int> simiv;
map<int, pair<int, int>> m;
static int tail;
static int root;
static int cnt;
void mid() {
    if (miv.empty()) {
        return;
    }
    int a = miv.back();
    miv.pop_back();
    if (m[a].first != -1) {
        miv.push_back(m[a].first);
        mid();
    }
    tail = a;
    if (m[a].second != -1) {
        miv.push_back(m[a].second);
        mid();
    }
}
void simid() {
    if (simiv.empty()) return;
    int a = simiv.back();
    simiv.pop_back();
    visited[a] = true;
    cnt++;
    if (m[a].first != -1 && !visited[m[a].first]) {
        simiv.push_back(m[a].first);
        simid();
    }
    if (m[a].second != -1 && !visited[m[a].second]) {
        simiv.push_back(m[a].second);
        simid();
    }
    if (a == tail) {
        cout << cnt-1;
        return;
    }
    if (a != root) {
        cnt++;
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    visited = vector<bool>(N + 1, false);
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        m[x] = { y,z };
        if(y!=-1)
            visited[y] = true;
        if(z!=-1)
            visited[z] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) root = i;
    }
    visited = vector<bool>(N + 1, false);
    miv.push_back(1);
    mid();
    simiv.push_back(root);
    simid();
}
