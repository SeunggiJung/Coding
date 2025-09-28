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
    vector<pair<vector<int>, vector<int>>> dp(N);
    for (int i = 0; i < N; i++) {
        vector<int> arr;
        for (int j = 0; j <= i; j++) {
            int index = lower_bound(arr.begin(), arr.end(), v[j]) - arr.begin();
            if (index == arr.size()) arr.push_back(v[j]);
            else arr[index] = v[j];
        }
        dp[i].first = arr;
    }
    
    for (int i = 0; i < N; i++) {
        vector<int> arr;
        for (int j = N-1; j >= i; j--) {
            int index = lower_bound(arr.begin(), arr.end(), v[j]) - arr.begin();
            if (index == arr.size()) arr.push_back(v[j]);
            else arr[index] = v[j];
        }
        dp[i].second = arr;
    }
    int maxi = 0;
    
    for (int i = 0; i < N - 1; i++) {
        int len = dp[i].first.size() + dp[i + 1].second.size();
        if (dp[i].first.back() == dp[i + 1].second.back()) len--;
        maxi = max(maxi, len);
    }
    cout << maxi;
}