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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int B, R, T;
    cin >> B >> R >> T;
    int cnt = 1;
    //vector<pair<int, int>> v(116401,{0,0});
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> sm;
    vector<int> js;
    int bs = 0, rs = 0;
    for (int i = 0; i < T; i++) {
        int t, m;
        char c;
        cin >> t >> c >> m;
        if (c == 'B') {
            if (t < bs) t = bs;
            for (int j = 0; j < m; j++) {
                pq.push({ t,0 });
                t += B;
            }
            bs = t;
        }
        else {
            if (t < rs) t = rs;
            for (int j = 0; j < m; j++) {
                pq.push({ t,1 });
                t += R;
            }
            rs = t;
        }
    }
    while (!pq.empty()) {
        int t, c;
        c = pq.top().second;
        pq.pop();
        if (!c) sm.push_back(cnt);
        else js.push_back(cnt);
        cnt++;
    }
    cout << sm.size() << "\n";
    for (auto& i : sm) cout << i << " ";
    cout << "\n";
    cout << js.size() << "\n";
    for (auto& i : js) cout << i << " ";
}