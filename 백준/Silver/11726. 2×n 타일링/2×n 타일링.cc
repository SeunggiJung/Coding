#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N, M, T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<vector<int>> v(2, vector<int>(N, 0));
    v[0][0] = 1;
    v[0][1] = 1;
    v[1][1] = 1;
    for (int i = 2; i < N; i++) {
        v[0][i] = (v[0][i - 1] + v[1][i - 1]) % 10007;
        v[1][i] = (v[0][i - 2] + v[1][i - 2]) % 10007;
    }
    cout << (v[0][N - 1] + v[1][N - 1]) % 10007;
}