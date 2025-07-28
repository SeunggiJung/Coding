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
    long long int N;
    cin >> N;
    if (N == 1) { cout << "1"; return 0; }
    long long int level = 1;
    long long int start = 2;
    while (start <= N) {
        start += 6 * level;
        level++;
    }
    cout<<level;
}