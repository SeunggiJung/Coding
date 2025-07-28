#include <iostream>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
static long long int sum;
static int N;
struct compare1 {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
struct compare2 {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

void func(map<int, vector<pair<int, int>>> m) {
    vector<bool> visited1(N + 1, false);
    vector<bool> visited2(N + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare1> pq1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare2> pq2;
    pq1.push({ 0, 1 });
    pq2.push({ 0,1 });
    long long int weight1 = 0;
    long long int weight2 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while (!pq1.empty()) {
        int V = pq1.top().first;
        long long int w = pq1.top().second;
        pq1.pop();
        if (visited1[V]) continue;
        visited1[V] = true;
        weight1 += pow(w-1, 2);
        for (int i = 0; i < m[V].size(); i++) {
            pq1.push({ m[V][i].first, m[V][i].second });
        }
    }
    while (!pq2.empty()) {
        int V = pq2.top().first;
        long long int w = pq2.top().second;
        pq2.pop();
        if (visited2[V]) continue;
        visited2[V] = true;
        weight2 += pow(w-1, 2);
        for (int i = 0; i < m[V].size(); i++) {
            pq2.push({ m[V][i].first, m[V][i].second });
        }
    }
    cout << weight1*weight1 - weight2 * weight2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sum = 0;
    int V, E;
    cin >> V >> E;
    N = V;
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < E+1; i++) {
        int r, c;
        cin >> r >> c;
        int value;
        cin >> value;
        m[r].push_back({ c, value });
        m[c].push_back({ r, value });
        sum += value;
    }

    func(m);
}