#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
static long long int sum;
static long long int N, M;
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
    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> M;
        v.push_back(M);
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        cout << v[i - 1] * i - sum << " ";
        sum += v[i - 1] * i - sum;
    }
}