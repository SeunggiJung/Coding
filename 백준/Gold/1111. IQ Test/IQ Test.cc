#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
static int N, M;
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
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    if (N == 1) {
        cout << "A";
        return 0;
    }
    if (N == 2) {
        if (v[0] == v[1]) {
            cout << v[1];
        }
        else cout << "A";
        return 0;
    }
    int q=0, r;
    if (v[1] != v[0]) {
        q = (v[2] - v[1]) / (v[1] - v[0]);
    }
    r = v[1] - v[0] * q;
    for (int i = 0; i < N-1; i++) {
        if (v[i] * q + r != v[i + 1]) {
            cout << "B";
            return 0;
        }
    }
    cout << q * v[N - 1] + r;
}