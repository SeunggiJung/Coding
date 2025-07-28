#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
const int MAX_N = 5000;
vector<int> primes;
vector<bool> is_prime(MAX_N + 1, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX_N; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_N; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p <= MAX_N; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

long long count_prime_factor(int n, int p) {
    long long count = 0;
    while (n > 0) {
        count += n / p;
        n /= p;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    sieve();
    for (int i = 0; i < T; i++) {
        int N1, R1, N2, R2;
        cin >> N1 >> R1 >> N2 >> R2;
        vector<long long> exp1_counts(MAX_N + 1, 0);
        vector<long long> exp2_counts(MAX_N + 1, 0);

        bool coprime = true;

        for (int p : primes) {
            if (p > N1 && p > N2) break;

            long long count_N1 = count_prime_factor(N1, p);
            long long count_R1 = count_prime_factor(R1, p);
            long long count_N1_minus_R1 = count_prime_factor(N1 - R1, p);
            exp1_counts[p] = count_N1 - count_R1 - count_N1_minus_R1;

            long long count_N2 = count_prime_factor(N2, p);
            long long count_R2 = count_prime_factor(R2, p);
            long long count_N2_minus_R2 = count_prime_factor(N2 - R2, p);
            exp2_counts[p] = count_N2 - count_R2 - count_N2_minus_R2;

            if (exp1_counts[p] > 0 && exp2_counts[p] > 0) {
                coprime = false;
                break;
            }
        }

        if (coprime) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
}