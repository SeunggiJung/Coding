#include <iostream>
#include <queue>
#include <map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        bool flag = false;
        if (v[i] == 1) continue;
        for (int j = 2; j < v[i] / 2+1; j++) {
            if (v[i] % j == 0) flag = true;
        }
        if (!flag) cnt++;
    }
    cout << cnt;
}