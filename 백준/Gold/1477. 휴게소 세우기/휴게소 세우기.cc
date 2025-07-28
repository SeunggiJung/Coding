#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
static int N, M, L;
vector<int> v;
bool check(int mid) {
    int cnt = 0;
    for (int i = 1; i < v.size(); i++) {
        int dist = v[i] - v[i - 1];
        cnt += dist / mid;
        if (dist % mid == 0) cnt--;
    }
    if (cnt > M) return false;
    else return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> L;
    v.push_back(0);
    v.push_back(L);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int start = 1;
    int end = L;
    int ans = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (check(mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    cout << ans;
}