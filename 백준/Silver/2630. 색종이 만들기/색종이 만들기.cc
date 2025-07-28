#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> v;
int b=0,w = 0;
int N;
void func(int len, int x, int y) {
    bool flag = true;
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (v[i][j] != v[x][y]) {
                flag = false; break;
            }
        }
    }
    if (flag) {
        if (v[x][y]) w += 1;
        else b += 1;
        return;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(len / 2, x + (i * (len / 2)), y + (j * (len / 2)));
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    v = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    func(N, 0, 0);
    cout << b << "\n" << w;
}