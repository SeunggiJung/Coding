#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;
static int N, M, L;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    for (int i = 0; i < N; i++) {
        long long int a;
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < M; i++) {
        long long int x = pq.top();
        pq.pop();
        long long int y = pq.top();
        pq.pop();
        x = x + y;
        pq.push(x);
        pq.push(x);
    }
    long long int sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
}