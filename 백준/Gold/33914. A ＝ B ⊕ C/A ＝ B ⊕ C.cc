#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
static int N, M, T;
string in;
vector<bool> visited;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ones, zeros;
    cin >> ones >> zeros;
    vector<vector<ll>> dp(ones+zeros+1, vector<ll>(ones+zeros+1, 0));
    dp[0][3] = 1;
    dp[2][1] = 3;
    for (int i = 6; i <= ones + zeros; i = i + 3) {
        dp[0][i] = 1;
        for (int j = 2; i-j>0; j += 2) {
            dp[j][i - j] = (dp[j - 2][i - j - 1] * 3) % 1000000007;
            if ((i - j - 3) > 0) dp[j][i - j] = (dp[j][i - j] + dp[j][i - j - 3]) % 1000000007;
        }
    }
    cout << dp[ones][zeros];
}