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
map<int, pair<int, int>> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> A;
    vector<int> v(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    vector<int> s(N+1,0);
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += v[i];
        s[i] = sum;
    }
    for (int i = 0; i < A; i++) {
        int st, en;
        cin >> st >> en;
        cout << s[en] - s[st - 1] << "\n";
    }
}
