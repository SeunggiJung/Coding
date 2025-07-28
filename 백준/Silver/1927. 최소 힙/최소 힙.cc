#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <time.h>
#include <list>
using namespace std;
static long long int N, M;
static vector<vector<int>> v;
static vector<int> visited;
static int maxi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        cin >> M;
        if (M == 0) {
            if (pq.empty())
                cout << 0 << "\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(M);
    }
}
