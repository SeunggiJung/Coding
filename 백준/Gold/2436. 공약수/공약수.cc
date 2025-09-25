#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;
typedef pair<int, int> pii;
int uclid(int A, int B) {
    int t1 = 0, t2 = 1;
    while (B != 0) {
        int r = A % B;
        int div = A / B;
        int t = t1 - t2 * div;
        A = B;
        B = r;
        t1 = t2;
        t2 = t;
    }
    return A;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int  N, M;
    cin >> N >> M;
    long long int mult = N * M;
    long long int before = 100000001;
    long long int mini = LLONG_MAX;
    pair<long long int , long long int> ans;
    for (long long int i = N; i <= sqrt(mult); i += N) {
        if (mult % i == 0 && i + mult / i < mini && gcd(i, mult/i)==N) {
            ans = { i, mult / i };
            mini = i + mult / i;
        }
    }
    cout << ans.first << " " << ans.second;
}