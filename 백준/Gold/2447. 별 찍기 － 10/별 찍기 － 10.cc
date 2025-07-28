#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<vector<bool>> v;
int N, M;
void func(int len, int x, int y) {
    if (len == 1) { 
        v[x][y] = true;
        return; 
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j==1) continue;
            func(len / 3, x + (len / 3) * i, y + (len / 3) * j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    v = vector<vector<bool>>(N+1, vector<bool>(N+1, false));
    func(N,0,0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j]) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}