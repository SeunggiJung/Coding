#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
static int N, M, K;
vector<int> v;
map<int, lli> m;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<int> sum(N + 1, 0);
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        sum[i] = v[i] + sum[i-1];
    }
    m[sum[0]] = 1;
    lli cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (m.count(sum[i] - M)) {
            cnt += m[sum[i] - M];
        }
        m[sum[i]]++;
    }
    cout << cnt;
}