#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int T, n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for (int i = 0; i < T; i++) {
        map<string, int> m;
        cin >> n;
        for (int j = 0; j < n; j++) {
            string name, obj;
            cin >> name >> obj;
            if (!m[obj]) m[obj] = 0;
            m[obj]++;
        }
        int sum = 1;
        for (auto& x : m) {
            sum *= (x.second+1);
        }
        cout << sum - 1 << "\n";
    }
}