#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    if (N == 1) {
        cout << 1; return 0;
    }
    vector<pair<pii,pii>> dp(N);
    vector<int> arr;
    for (int j = 0; j < N; j++) {
        int index = lower_bound(arr.begin(), arr.end(), v[j]) - arr.begin();
        if (index == arr.size()) arr.push_back(v[j]);
        else arr[index] = v[j];
        dp[j].first = { arr.size(), arr.back() };
    }
    arr.clear();
    for (int j = N-1; j >=0; j--) {
        int index = lower_bound(arr.begin(), arr.end(), v[j]) - arr.begin();
        if (index == arr.size()) arr.push_back(v[j]);
        else arr[index] = v[j];
        dp[j].second = { arr.size(), arr.back() };
    }
    int maxi = 0;
    
    for (int i = 0; i < N - 1; i++) {
        int len = dp[i].first.first + dp[i + 1].second.first;
        if (dp[i].first.second == dp[i + 1].second.second) len--;
        maxi = max(maxi, len);
    }
    cout << maxi;
}