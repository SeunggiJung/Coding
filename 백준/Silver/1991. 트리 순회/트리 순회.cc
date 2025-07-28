#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M;
static vector<vector<int>> v;
static vector<int> visited;
static vector<char> prv;
static vector<char> miv;
static vector<char> pov;
map<char, pair<char, char>> m;
void pre() {
    if (prv.empty()) return;
    char a = prv.back();
    cout << a;
    prv.pop_back();
    if (m[a].first != '.') {
        prv.push_back(m[a].first);
        pre();
    }
    if (m[a].second != '.') {
        prv.push_back(m[a].second);
        pre();
    }
}
void mid() {
    if (miv.empty()) {
        return;
    }
    char a = miv.back();
    miv.pop_back();
    if (m[a].first != '.') {
        miv.push_back(m[a].first);
        mid();
    }
    cout << a;
    if (m[a].second != '.') {
        miv.push_back(m[a].second);
        mid();
    }
}
void post() {
    if (pov.empty()) {
        return;
    }
    char a = pov.back();
    pov.pop_back();
    if (m[a].first != '.') {
        pov.push_back(m[a].first);
        post();
    }
    if (m[a].second != '.') {
        pov.push_back(m[a].second);
        post();
    }
    cout << a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        char x, y, z;
        cin >> x >> y >> z;
        m[x] = { y,z };
    }
    prv.push_back('A');
    pre();
    cout << "\n";
    miv.push_back('A');
    mid();
    cout << "\n";
    pov.push_back('A');
    post();
}
