#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<pii> v;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        v.push_back({ A,B });
    }
    sort(v.begin(), v.end());
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int index = lower_bound(arr.begin(), arr.end(), v[i].second) - arr.begin();
        if (index == arr.size()) {
            arr.push_back(v[i].second);
        }
        else arr[index] = v[i].second;
    }
    cout << N - arr.size();
}