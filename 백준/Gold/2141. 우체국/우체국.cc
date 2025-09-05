#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    vector<pii> XA(N + 1);
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> XA[i].first >> XA[i].second;
        sum += XA[i].second;
    }
    sort(XA.begin()+1, XA.end());
    long long cur = 0;
    for (int i = 1; i <= N; i++) {
        cur += XA[i].second;
        if (cur >= (sum + 1) / 2) {
            cout << XA[i].first;
            break;
        }
    }
}