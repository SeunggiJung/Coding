#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<bool> hansoo(1001, false);
    for (int i = 1; i < 1000; i++) {
        if (i < 100) {
            hansoo[i] = true;
            continue;
        }
        int num = i;
        int h = num / 100;
        num -= h * 100;
        int t = num / 10;
        int o = i % 10;
        if ((h - t) == (t - o)) hansoo[i] = true;
    }
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (hansoo[i]) cnt++;
    }
    cout << cnt;
}