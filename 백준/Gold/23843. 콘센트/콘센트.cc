#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
static lli N, M, K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    priority_queue<lli, vector<lli>, greater<lli>> v;
    for (int i = 0;i < M;i++) v.push(0);
    priority_queue<lli> pq;
    for (int i = 0;i < N;i++) {
        cin >> K;
        pq.push(K);
    }
    while (!pq.empty()) {
        lli a = pq.top();
        pq.pop();
        lli space = v.top();
        v.pop();
        space += a;
        v.push(space);
    }
    lli out;
    while (!v.empty()) {
        out = v.top();
        v.pop();
    }
    cout << out;

}