#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
static long long int sum;
static long long int N, M;
static int mi, zero, pl;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<int> v(N + 1, 0);
    map < int, vector<int>> m;
    for (int i = 1; i <= N; i++) {
        vector<int> x;
        m.insert({ i,x });
    }
    queue<int> q;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        v[y]++;
        m[x].push_back(y);
    }
    int cnt = 0;
    while (true) {
        for (int i = 1; i <= N; i++) {
            if (v[i] == 0) {
                int len = m[i].size();
                q.push(i);
                v[i] = -1;
                cnt++;
                bool flag = false;
                for (int j = 0; j < len; j++) {
                    v[m[i][j]] -= 1;
                    if (v[m[i][j]] == 0) flag = true;
                }
                if (flag)break;
            }
        }
        if(cnt==N) break;
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}