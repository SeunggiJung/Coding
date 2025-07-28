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
    int N;
    cin >> N;
    string in;
    cin >> in;
    long long int mod = 1234567891;
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        long long int x = 1;
        for (int j = 0; j < i; j++) {
            x *= 31;
            x = x % mod;
        }
        sum += ((in[i] - 'a' + 1) * x) % 1234567891;
    }
    cout << sum % 1234567891;
}