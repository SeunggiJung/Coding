#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, R;
    cin >> N >> M;
    int on = N, om = M;
    while (true) {
        R = N % M;
        if (!R) { cout << M << "\n"; break; }
        N = M;
        M = R;
    }
    cout << (on / M) * om;
}