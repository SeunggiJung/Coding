#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
static long long int sum;
static long long int N, M;
static int mi, zero, pl;
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
    for (int i = 0; i < N; i++) {
        int x;
        string in;
        cin >> x >> in;
        for (int j = 0; j < in.length(); j++) {
            for (int k = 0; k < x; k++) {
                cout << in[j];
            }
        }
        cout << '\n';
    }
}