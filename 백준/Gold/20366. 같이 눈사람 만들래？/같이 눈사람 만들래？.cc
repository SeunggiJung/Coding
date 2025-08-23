#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<vector<int>> sums;
bool check(int a, int b) {
    if (sums[a][1] != sums[b][1] && sums[a][1] != sums[b][2] && sums[a][2] != sums[b][1] && sums[a][2] != sums[b][2]) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> snows(N);
    for (int i = 0; i < N; i++) cin >> snows[i];
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            sums.push_back({ snows[i] + snows[j], i,j });
        }
    }
    sort(sums.begin(), sums.end());
    int mini = INT32_MAX;
    int left = 1, right = 2;
    while (left < right) {
        left = right-1;
        bool flag = true;
        if (check(left,right)) {
            mini = min(mini, abs(sums[left][0] - sums[right][0]));
        }
        right++;
        if (right == sums.size()) break;
    }
    cout << mini;
}