#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
static int N, M, K;
vector<int> v;
vector<pii> tree;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    v = vector<int>(N);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        pq.push({ v[i],i });
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int order;
        cin >> order;
        if (order == 1) {
            int index, value;
            cin >> index >> value;
            v[index-1] = value;
            pq.push({ value, index-1 });
        }
        else {
            while (!pq.empty()) {
                int index, value;
                index = pq.top().second;
                value = pq.top().first;
                if (v[index] == value) { cout << index+1<<"\n"; break; }
                pq.pop();
            }
        }
    }

}