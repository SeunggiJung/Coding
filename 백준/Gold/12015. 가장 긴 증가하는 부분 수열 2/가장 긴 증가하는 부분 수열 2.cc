#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int index = lower_bound(arr.begin(), arr.end(), v[i]) - arr.begin();
        if (index == arr.size()) arr.push_back(v[i]);
        else arr[index] = v[i];
    }
    cout << arr.size();
}