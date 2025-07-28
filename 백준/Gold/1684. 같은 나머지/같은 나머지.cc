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
static int N, M, K;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N);
    int mini = INT32_MAX;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (!i) continue;
        mini = (mini, abs(v[i - 1] - v[i]));
    }
    for (int i = mini; i > 0; i--) {
        int R = v[0] % i;
        if (R < 0) R += i;
        bool flag = true;
        for (int j = 1; j < N; j++) {
            int rem = v[j] % i;
            if (rem < 0)rem += i;
            if (rem != R) {
                flag = false; break;
            }
        }
        if (flag) {
            cout << i; break;
        }
    }
}