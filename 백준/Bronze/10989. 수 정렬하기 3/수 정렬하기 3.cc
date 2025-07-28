#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(10001, 0);
    int m = 0;
    for (int i = 0; i < N; i++) {
        int in;
        cin >> in;
        m = max(m, in);
        a[in]++;
    }
    for (int i = 1; i <= m; i++) {
        if (!a[i])continue;
        for (int j = 0; j < a[i]; j++) {
            cout << i << "\n";
        }
    }
}