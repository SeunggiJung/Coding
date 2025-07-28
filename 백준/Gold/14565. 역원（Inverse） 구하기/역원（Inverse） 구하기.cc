#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, A;
static vector<vector<int>> v;
static vector<bool> visited;
map<int, pair<int, int>> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> A;
    long long int origiN = N;
    long long int origiA = A;
    long long int z = 0, t = 1;
    while (true) {
        long long int div;
        long long int mod;
        div = N / A;
        mod = N % A;
        N = A;
        A = mod;
        long long int bez = z;
        z = t;
        t = bez - t * div;
        if (!mod) break;
    }
    if (z < 0) z += origiN;
    if (N!=1) z = -1;
    cout << origiN-origiA<<" "<<z;
}
