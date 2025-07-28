#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
static int N, M;
static int A, B;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    priority_queue <pair<int, int >,vector<pair<int,int>>, greater<pair<int,int>>> q;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        q.push({ A,B });
    }
    int cnt = 1;
    priority_queue<int,vector<int>, greater<int>> ends;
    ends.push(q.top().second);
    q.pop();
    while (!q.empty()) {
        int st = q.top().first;
        int et = q.top().second;
        q.pop();
        int bef = ends.top();
        if (st < bef) {
            cnt++;
        }
        else {
            ends.pop();
        }
        ends.push(et);
    }
    cout << cnt;
}
