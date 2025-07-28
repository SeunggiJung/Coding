#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
vector<vector<bool>> ent;
int T, n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for (int i = 0; i < T; i++) {
        priority_queue<pis, vector<pis>, greater<pis>> pq;
        map<string, bool> m;
        cin >> n;
        string in;
        bool flag = true;
        for (int j = 0; j < n; j++) {
            cin >> in;
            pq.push({ in.length(), in });
        }
        while (!pq.empty()) {
            string x = pq.top().second;
            pq.pop();
            for (int k = 0; k < x.length(); k++) {
                if (m[x.substr(0, k + 1)]) {
                    flag = false;
                }
            }
            m[x] = true;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}