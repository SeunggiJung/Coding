#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M, T;
vector<int> primes = { 1,2,3,5,7,9 };
bool isprime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}
void bt(int depth, int num) {
    if(num&& !isprime(num)) return;
    if (depth == N) {
        cout << num << "\n";
        return;
    }
    for (int i = 0; i < 6; i++) {
        num = num * 10 + primes[i];
        bt(depth + 1, num);
        num /= 10;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    if (N == 1) {
        cout << "2\n3\n5\n7";
        return 0;
    }
    bt(0, 0);
}