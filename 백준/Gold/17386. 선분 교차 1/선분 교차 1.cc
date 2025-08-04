#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
long long int x, y;
vector<pll> dots;
long long int CCW(pll A, pll B, pll C) {
    long long tmp = A.first * B.second + B.first * C.second + C.first * A.second;
    tmp -= B.first * A.second + C.first * B.second + A.first * C.second;
    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else return -1;
}
int func(pll A, pll B, pll C, pll D) {
    long long int ccw1 = CCW(A, B, C) * CCW(A, B, D);
    long long int ccw2 = CCW(C, D, A) * CCW(C, D, B);
    if (ccw1 == 0 && ccw2 == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        if (A <= D && B >= C) return 1;
        return 0;
    }
    if (ccw1 <= 0 && ccw2 <= 0) return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        dots.push_back({ x,y });
    }
    cout << func(dots[0], dots[1], dots[2], dots[3]);
}