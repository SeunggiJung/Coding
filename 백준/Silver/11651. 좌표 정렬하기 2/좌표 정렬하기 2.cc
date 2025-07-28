#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pq.push({ x,y });
    }
    while (!pq.empty()) {
        cout << pq.top().first << ' ' << pq.top().second << "\n";
        pq.pop();
    }
}