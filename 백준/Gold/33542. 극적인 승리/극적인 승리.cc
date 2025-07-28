#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
vector<int> v;
int X, Y, N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> X >> Y >> N;
    vector<pii> left(N + 1, { 0,-1 });
    vector<pii> right(N + 1, { 0,-1 });
    for (int i = 1; i <= N; i++) {
        cin >> left[i].first >> right[i].first;
        left[i].second = i;
        right[i].second = i;
    }
    if (Y > X) {
        cout << "-1 -1";
        return 0;
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    int mini = 200000001;
    int lans = -1;
    int rans = -1;
    for (int i = 0; i <= N; i++) {
        if (left[i].first > mini) continue;
        int start = -1;
        int end = N + 1;
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            int val = left[i].first + right[mid].first;
            if (val + Y > X) {
                end = mid; 
                if (left[i].second == right[mid].second) {
                    if (mid != N)
                    {
                        val = left[i].first + right[mid + 1].first; mid += 1;
                    }
                    else continue;
                }
                if (val < mini) {
                    mini = val;
                    lans = left[i].second;
                    rans = right[mid].second;
                }
            }
            else {
                start = mid;
            }
        }
    }
    if (mini == 200000001) cout << "No";
    else cout << lans << " " << rans;
}