#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
static int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>> v(1001);
    for (int i = 1; i <= 1000; i++) {
        v[i] = vector<int>(i+1, 1);
    }
    v[1][0] = 1;
    v[1][1] = 1;
    v[2][0] = 1;
    v[2][1] = 2;
    v[2][2] = 1;
    for (int i = 3; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j || j == 0) {
                v[i][j] = 1; continue;
            }
            v[i][j] = (v[i - 1][j]%10007 + v[i - 1][j - 1]%10007) % 10007;
        }
    }
    cin >> N >> M;
    cout << v[N][M];
}