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
    vector<vector<int>> v(15, vector<int>(14));
    v[0] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < 14; j++) {
            for (int k = 0; k <= j; k++) {
                v[i][j] += v[i - 1][k];
            }
        }
    }
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int k, n;
        cin >> k >> n;
        cout << v[k][n-1] << "\n";
    }
}