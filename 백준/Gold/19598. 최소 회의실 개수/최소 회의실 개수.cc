#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M, T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        pq.push({ s,1 });
        pq.push({ e,0 });
    }
    int ans = 0;
    while (!pq.empty()) {
        
        int t = pq.top().first;
        int se = pq.top().second;
        pq.pop();
        
        
        if (se) { cnt++; ans = max(cnt, ans); }
        else cnt--;
        
    }
    cout << ans;
}