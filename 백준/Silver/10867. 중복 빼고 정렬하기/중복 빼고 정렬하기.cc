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
    vector<int> v;
    set<int> s;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        v.push_back(A);
    }
    sort(v.begin(), v.end());
    for (auto i : v) s.insert(i);
    for (auto i : s) cout << i << " ";
}