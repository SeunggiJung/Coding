#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;
typedef unsigned long long int lli;
typedef pair<lli, lli> pll;
static int N;
static lli M;
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
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    lli start = v.front(), end = v.front() * M;
    while (start <= end) {
        lli mid = (start + end) / 2;
        lli cnt = 0;
        for (int i = 0; i < N; i++) cnt += (mid / v[i]);
        if (cnt >= M) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    cout << start;
}