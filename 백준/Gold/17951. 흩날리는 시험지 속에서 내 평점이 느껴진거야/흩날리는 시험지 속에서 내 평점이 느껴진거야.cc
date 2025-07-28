#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
vector<int> v;
int N, M, T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<int> point(N);
    int end = 1;
    for (int i = 0; i < N; i++) {
        cin >> point[i];
        end += point[i];
    }
    int start = 0;
    if (M == 1) {
        cout << end - 1;
        return 0;
    }
    while (start + 1 < end) {
        int mid = (start + end) / 2;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            sum += point[i];
            if (sum >= mid) {
                sum = 0;
                cnt++;
            }
        }
        if (cnt >= M) {
            start = mid;
        }
        else end = mid;
    }
    cout << start;
}