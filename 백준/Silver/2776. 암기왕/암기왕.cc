#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    map<int, bool> m;
    while (T-- > 0) {
        cin >> N;
        m.clear();
        for (int i = 0; i < N; i++) {
            int A;
            cin >> A;
            m[A] = true;
        }
        cin >> N;
        for (int i = 0; i < N; i++) {
            int A;
            cin >> A;
            if (m[A]) cout << 1 << "\n";
            else cout << "0\n";
        }
    }
}