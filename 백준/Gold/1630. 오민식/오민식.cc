#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int, int> pii; 
int N;
vector<bool> primes(1000001, true);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i <= sqrt(1000000); i++) {
        if (primes[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                primes[j] = false;
            }
        }
    }
    long long int oms = 1;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        if (primes[i]) {
            long long int x = 1;
            while (true) {
                if (x * i > N) break;
                x *= i;
            }
            oms *= x;
            oms %= 987654321;
        }
    }
    cout << oms;
}
