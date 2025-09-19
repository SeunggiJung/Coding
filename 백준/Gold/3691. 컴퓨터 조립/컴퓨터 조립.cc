#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
map <string, priority_queue<pii, vector<pii>, greater<pii>>> m;
vector<string> types;
int n, b;
int maxi = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> n >> b;
        m.clear();
        types.clear();
        maxi = 0;
        string type, name;
        int price, quality;
        for (int i = 0; i < n; i++) {
            cin >> type >> name >> price >> quality;
            if (m[type].empty()) types.push_back(type);
            m[type].push({ price, quality });
        }
        int sum = INT32_MAX;
        int cost = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> v(types.size(), 0);
        for (int i = 0; i < types.size(); i++) {
            string t = types[i];
            cost += m[t].top().first;
            sum = min(sum, m[t].top().second);
            pq.push({ m[t].top().second, m[t].top().first, i});
            //v[i] = m[t].top().second;
            m[t].pop();
        }
        while (!pq.empty()) {
            int index = pq.top()[2];
            string t = types[pq.top()[2]];
            int p = pq.top()[1];
            int q = pq.top()[0];
            pq.pop();
            v[index] = max(v[index], q);
            while (true) {
                if (m[t].empty()) break;
                int n_p = m[t].top().first;
                int n_q = m[t].top().second;
                m[t].pop();
                if (n_q <= q) continue;
                if (cost + n_p - p <= b) {
                    cost = cost + n_p - p;
                    pq.push({ n_q, n_p, index });
                    break;
                }
            }
        }
        sort(v.begin(), v.end());
        cout << v[0] << "\n";
    }
}