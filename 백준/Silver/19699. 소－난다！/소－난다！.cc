#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M;
static vector<int> v;
static vector<bool> visited;
static vector<bool> isprime;
static vector<int> out;
static int cnt;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
void bt(vector<int> vin) {
    if (vin.size() == M) {
        int sum = 0;
        for (int i = 0; i < vin.size(); i++) {
            sum += v[vin[i]];
        }
        if (isprime[sum]) {
            isprime[sum] = false;
            out.push_back(sum);
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i])continue;
        vin.push_back(i);
        visited[i] = true;
        bt(vin);
        visited[i] = false;
        vin.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cnt = 0;
    cin >> N >> M;
    int max_value = 0;
    v = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        max_value = max(max_value, v[i]);
    }
    visited = vector<bool>(N, false);
    isprime = vector<bool>(max_value * M + 1, true);
    for (int i = 2; i <= sqrt(max_value * M); i++) {
        if (isprime[i] == true) {
            for (int j = 2; i * j <= max_value * M; j++) {
                isprime[i * j] = false;
            }
        }
    }

    vector<int> vin;
    bt(vin);
    sort(out.begin(), out.end());
    if (out.empty()) {
        cout << -1;
    }
    else {
        for (int i = 0; i < out.size(); i++) {
            cout << out[i] << " ";
        }
    }
}
