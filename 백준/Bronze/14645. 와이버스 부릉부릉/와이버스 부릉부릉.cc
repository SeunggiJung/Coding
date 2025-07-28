#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
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
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
    }
    cout << "비와이";
}