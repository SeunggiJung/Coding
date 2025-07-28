#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> v;
    cin >> N;
    map<int, int> out;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        int in;
        cin >> in;
        pq.push(in);
        v.push_back(in);
    }
    int cnt = 1;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if (!out[x]) { 
            out[x] = cnt; cnt++; 
        }
    }
    for (int i = 0; i < N; i++) {
        cout << out[v[i]]-1 << " ";
    }
}