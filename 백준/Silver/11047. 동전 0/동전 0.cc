#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int cnt = 0;
    while (true) {
        for (int i = 0; i < N; i++) {
            if (v[i] > M)continue;
            cnt += M / v[i];
            M = M % v[i];
            if (M == 0) {
                cout << cnt;
                return 0;
            }
        }
    }
}
