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
    int T;
    cin >> T;
    string out;
    for (int i = 0; i < T; i++) {
        string N, M;
        cin >> N >> M;
        if (N == M) out.append("OK\n");
        else out.append("ERROR\n");
    }
    cout << out;
}