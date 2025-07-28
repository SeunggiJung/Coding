#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int T, n, m;
vector<vector<int>> v;
vector<int> Asum;
vector<int> Bsum;
typedef pair<int, int> pii;
map<int, int> As;
int goal;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
int sumA(int start, int end) {
    if (start == end) return Asum[start];
    return Asum[end] - Asum[start];
}
int sumB(int start, int end) {
    if (start == end) return Bsum[start];
    return Bsum[end] - Bsum[start];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T >> n;
    vector<int> A(n);
    long long int cnt = 0;
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sa += A[i];
        Asum.push_back(sa);
    }
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
        sb += B[i];
        Bsum.push_back(sb);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int s = sumA(i, j);
            if (!As[s]) As[s] = 0;
            As[s]++;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            int s = sumB(i, j);
            if (!As[T - s]) continue;
            cnt += As[T - s];
        }
    }
    cout << cnt;
}