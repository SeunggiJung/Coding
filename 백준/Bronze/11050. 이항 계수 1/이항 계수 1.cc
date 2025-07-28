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
    int N, K;
    cin >> N >> K;
    int a = 1;
    for (int i = N; i > (N - K); i--) {
        a *= i;
    }
    int b = 1;
    for (int i = 1; i <= K; i++) {
        b *= i;
    }
    cout << a / b;
}