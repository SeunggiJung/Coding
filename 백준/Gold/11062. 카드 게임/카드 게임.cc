#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
static int N, M, L;
vector<int> v;
vector<vector<int>> dp;
int calc(int left, int right, bool turn) {
    if (left > right)return 0;
    if (dp[left][right])return dp[left][right];
    if (turn) {
        return dp[left][right] = max(v[left] + calc(left+1, right, !turn), calc(left, right-1, !turn) + v[right]);
    }
    else {
        return dp[left][right] = min(calc(left + 1, right, !turn), calc(left, right - 1, !turn));
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
        int sum = 0;
        v = vector<int>(N+1);
        dp = vector<vector<int>>(N+1, vector<int>(N+1, 0));
        for (int j = 1; j <= N; j++) {
            cin >> v[j];
        }
        cout<< calc(1, N, true) << "\n";
    }
}