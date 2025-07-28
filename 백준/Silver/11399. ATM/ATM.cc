#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
static long long int N, M,K;
static vector<vector<int>> v;
static vector<bool> visited;
static vector<int> out;
static vector<bool> kn;
static int max_value;
struct compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            sum += v[j];
        }
    }
    cout << sum;
}
