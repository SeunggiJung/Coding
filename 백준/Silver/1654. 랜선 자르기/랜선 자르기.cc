#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
static lli N, M, K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<lli> v(N);
    lli maxi = 0;
    for (int i = 0;i < N;i++) {
        cin >> v[i];
        maxi = max(v[i], maxi);
    }
    lli able = 0, disable = maxi+1;
    lli mid;
    while (able + 1 < disable) {
        mid = (able + disable) / 2;
        lli sum = 0;
        for (int i = 0;i < N;i++) {
            if (v[i] >= mid) sum += v[i] / mid;
        }
        if (sum >= M) {
            able = mid;
        }
        else disable = mid;
    }
    cout << able;
    return 0;

}