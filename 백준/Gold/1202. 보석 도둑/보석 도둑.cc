#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
static int N, T;
vector<vector<int>> board;
vector<vector<int>> p;
vector<int> travel;
long long int maxi = 0;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> T;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> jew;
    for (int i = 0; i < N; i++) {
        int M, V;
        cin >> M >> V;
        jew.push({ M,V });
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < T; i++) {
        int W;
        cin >> W;
        pq.push(W);
    }
    vector<pair<int, int>> j;
    priority_queue<int> values;
    while (!pq.empty()) {
        int bag = pq.top();
        pq.pop();
        while (!jew.empty()) {
            int w = jew.top().first;
            int v = jew.top().second;
            if (w <= bag) {
                values.push(v);
                jew.pop();
            }
            else break;
        }
        if (!values.empty()) {
            maxi += values.top();
            values.pop();
        }
    }
    cout << maxi;
}