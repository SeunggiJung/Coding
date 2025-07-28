#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N, M, T;
vector<bool> visited;
vector<pair<int, int>> ans;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        pq.push({ N,M });
    }
    int maxi = 0;
    int cnt = 1;
    int st = pq.top().first;
    int et = pq.top().second;
    pq.pop();
    
    while (!pq.empty()) {
        if (pq.top().first >= et) {
            st = pq.top().first;
            et = pq.top().second;
            cnt++;
        }
        pq.pop();
    }
    cout << cnt;
}