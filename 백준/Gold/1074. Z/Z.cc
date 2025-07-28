#include <iostream>
#include <math.h>
using namespace std;
long long N, r, c;
long long cnt = 0;
void func(long long len, long long x, long long y) {
    if (x == r && y == c) {
        cout << cnt;
        return;
    }
    long long  startx = x, starty = y;
    if (r >= x + len / 2) {
        cnt += (len * len) / 2;
        startx += len / 2;
    }
    if (c >= y + len / 2) {
        cnt += (len / 2) * (len / 2);
        starty += len / 2;
    }
    func(len / 2, startx, starty);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> r >> c;
    func(pow(2,N), 0, 0);
}