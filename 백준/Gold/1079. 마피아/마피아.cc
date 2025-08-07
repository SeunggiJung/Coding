#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N, ej;
vector<vector<int>> R;
int maxi = 0;
void bt(int nights, vector<int> guilty, vector<bool> alive, bool day) {
    int alives = 0;
    for (int i = 1; i <= N; i++) {
        if (alive[i]) alives++;
    }
    if (alives == 1) {
        return;
    }
    if (!day) {
        maxi = max(maxi, nights);
        for (int i = 1; i <= N; i++) {
            if (i == ej) continue;
            if (alive[i]) {
                alive[i] = false;
                vector<int> tmp = guilty;
                for (int j = 1; j <= N; j++) {
                    tmp[j] += R[i][j];
                }
                bt(nights, tmp, alive, true);
                alive[i] = true;
            }
        }
    }
    else {
        int who = 0, point = -100;
        for (int i = 1; i <= N; i++) {
            if (alive[i] && guilty[i]>point) {
                who = i;
                point = guilty[i];
            }
        }
        if (who == ej) {
            return;
        }
        alive[who] = false;
        bt(nights + 1, guilty, alive, false);
        alive[who] = true;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    R = vector<vector<int>>(N + 1, vector<int>(N + 1));
    vector<int> guilty(N + 1);
    vector<bool> alive(N + 1, true);
    alive[0] = false;
    for (int i = 1; i <= N; i++) cin >> guilty[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> R[i][j];
        }
    }
    cin >> ej;
    ej += 1;
    if (N % 2 == 0) {
        bt(1, guilty, alive, false);
    }
    else
        bt(0, guilty, alive, true);
    cout << maxi;
}