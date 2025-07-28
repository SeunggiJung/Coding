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
    cin >> N;
    vector<long long int> p(101);
    p[0] = 0;
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    for (int i = 6; i <= 100; i++) {
        p[i]=(p[i - 1] + p[i - 5]);
    }
    vector<int> out;
    for (int i = 0; i < N; i++) {
        cin >> A;
        cout << p[A] << "\n";
    }
}
