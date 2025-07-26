#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
static int T, N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0;i < N;i++) {
        cin >> v[i];
        pq.push(v[i]);
    }
    int cnt = 0;
    vector<int> res(N);
    vector<char> out;
    while (!pq.empty()) {
        int x = pq.top();
        res.push_back(x);
        pq.pop();
        out.push_back('+');
        while (res.back() == v[cnt]) {
            out.push_back('-');
            res.pop_back();
            cnt++;
            if (cnt == N) break;
        }
    }
    if (cnt != N) cout << "NO";
    else {
        for (auto& s : out) cout << s << "\n";
    }
}