#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <time.h>
using namespace std;
static long long int N, A;
static vector<int> v;
static vector<bool> visited;
map<string, vector<string>> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A;
        sum += A;
        v.push_back(A);
    }
    sort(v.begin(), v.end());
    int limit;
    cin >> limit;
    if (sum <= limit) {
        cout << v.back();
        return 0;
    }
    //limit = limit / N * N;
    int start = 1;
    int end = v.back();
    int maxi = 0;
    while (start <= end) {
        vector<int> v2 = { v.begin(),v.end() };
        int sum2 = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < N; i++) {
            if (v2[i] > mid) v2[i] = mid;
            sum2 += v2[i];
        }
        if (sum2 == limit) break;
        if (sum2 < limit) {
            start = mid + 1;
            maxi = max(maxi, mid);
        }
        if (sum2 > limit) {
            end = mid - 1;
        }

    }
    cout << (start + end) / 2;
}
