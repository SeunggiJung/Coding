#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <time.h>
using namespace std;
static long long int N, A;
static vector<vector<int>> v;
static vector<bool> visited;
map<string, vector<string>> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        string child, parent;
        cin >> child >> parent;
        m[child].push_back(parent);
    }

    string a, b;
    cin >> a >> b;
    string start = a;
    bool flag = false;
    while (true) {
        if (m[start].empty()) break;
        start = m[start][0];
        if (start == b) flag = true;
    }
    start = b;
    while (true) {
        if (m[start].empty())break;
        start = m[start][0];
        if (start == a)flag = true;
    }
    if (flag)cout << 1;
    else cout << 0;
}
