#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<bool> isprime(1000001, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i < sqrt(1000000); i++) {
        if (isprime[i]) {
            for (int j = 2; i * j <= 1000000; j++) {
                isprime[i * j] = false;
            }
        }
    }
    cin >> N >> M;
    for (int i = N; i <= M; i++) {
        if (isprime[i]) cout << i << "\n";
    }
}