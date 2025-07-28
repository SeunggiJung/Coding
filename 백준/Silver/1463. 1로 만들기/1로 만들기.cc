#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M;
static vector<int> v;
void d(int n, int cnt) {
    if (v[n]<cnt) return;
    v[n] = min(v[n], cnt);
    if (n == 1) return;

    if (n % 3 == 0) d(n / 3, cnt + 1);
    if (n % 2 == 0) d(n / 2, cnt + 1);
    d(n - 1, cnt + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    v = vector<int>(N + 1, 100001);
    d(N, 0);
    cout << v[1];
}
