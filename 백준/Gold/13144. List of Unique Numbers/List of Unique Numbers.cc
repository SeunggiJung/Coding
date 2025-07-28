#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
static int N, K;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    ll cnt = 0;
    int left = 0, right = 1;
    vector<bool> visited(100001, false);
    //cnt += N;
    visited[v[left]] = true;
    while (left <= right) {
        if (right == N) {
            while (left <= right) {
                cnt += right - left;
                left++;
            }
            break;
        }
        if (visited[v[right]]) {
            cnt += right - left;
            visited[v[left]] = false;
            left++;
            continue;
            visited[v[left]] = true;
        }
        visited[v[right]] = true;
        right++;
    }
    cout <<cnt;
}