#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
static long long int sum;
static long long int N, M;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k, q, l, v, kn, ph;
    cin >> k >> q >> l >> v >> kn >> ph;
    cout << 1 - k << " " << 1 - q << " " << 2 - l << " " << 2 - v << " " << 2 - kn << " " << 8 - ph;
}