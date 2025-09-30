#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
vector<bool> primes(1000001, true);
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    primes[1] = false;
    for (int i = 2; i <= sqrt(1000000); i++) {
        for (int j = 2; i * j <= 1000000; j++) {
            if (primes[i]) primes[i * j] = false;
        }
    }
    cin >> N;
    if (N < 8) {
        cout << -1;
        return 0;
    }
    vector<int> Ns;
    if (N % 2 == 0) {
        Ns.push_back(2);
        Ns.push_back(2);
        int left = (N - 4) / 2;
        int right = (N - 4) / 2;
        while (true) {
            if (primes[left] && primes[right]) break;
            left--;
            right++;
            if (left<2 || right>N - 2) {
                cout << -1;
                return 0;
            }
        }
        Ns.push_back(left);
        Ns.push_back(right);
        for (auto i : Ns) cout << i << " ";
    }
    else {
        Ns.push_back(2);
        Ns.push_back(3);
        int left = (N - 5) / 2;
        int right = (N - 5) / 2;
        while (true) {
            if (primes[left] && primes[right]) break;
            left--;
            right++;
            if (left<2 || right>N - 2) {
                cout << -1;
                return 0;
            }
        }
        Ns.push_back(left);
        Ns.push_back(right);
        for (auto i : Ns) cout << i << " ";
    }
}