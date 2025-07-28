#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> v;
int T, M, N, x, y;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int N, M, x, y;
        cin >> N >> M >> x >> y;
        int A = N;
        int B = M;
        int t1 = 1, t2 = 0;
        while (B != 0) {
            int r = A % B;
            int div = A / B;
            int t = t1 - t2 * div;
            A = B;
            B = r;
            t1 = t2;
            t2 = t;
        }
        if (abs(x - y) % A != 0) {
            cout << "-1\n";
            continue;
        }
        int mult = (N * M) / A;
        for (int i = x; i <= mult; i += N) {
            if ((i - 1) % M + 1 == y) {
                cout << i << "\n";
                break;
            }
        }
    }
}