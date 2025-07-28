#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M;
static vector<int> v;
static vector<bool> visited;
static map<int, vector<pair<int, int>>> m;
static int mini;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};
void d(int n, int cnt) {
    if (n == N) {
        v[n]++;
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (n + i > N) continue;
        d(n + i, cnt + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        v = vector<int>(N + 1, 0);
        d(0, 0);
        cout << v[N] << "\n";
    }
    
}
