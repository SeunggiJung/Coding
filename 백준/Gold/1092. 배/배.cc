#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N;
    vector<int> crane(N);
    for (int i = 0; i < N; i++) {
        cin >> crane[i];
    }
    cin >> M;
    vector<int> box(M);
    for (int i = 0; i < M; i++) {
        cin >> box[i];
    }
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());
    vector<bool> visited(M, false);
    int time = 0;
    int cnt = 0;
    while (true) {
        bool flag = false;
        time++;
        for (int i = 0; i < N; i++) {
            int index = lower_bound(box.begin(), box.end(), crane[i]+1) - box.begin() - 1;
            for (int j = index; j >= 0; j--) {
                if (!visited[j]) {
                    visited[j] = true;
                    flag = true;
                    cnt++;
                    break;
                }
            }
        }
        if (cnt == M) break;
        if (!flag) {
            cout << -1;
            return 0;
        }
    }
    cout << time;
}