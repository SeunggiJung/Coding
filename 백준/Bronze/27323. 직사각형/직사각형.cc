#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
static long long int sum;
static int N, M;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    cout << N * M;
}