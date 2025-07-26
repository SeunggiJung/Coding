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
static int zero, one;
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
    vector<long long int> fibonacci(41, 0);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    fibonacci[2] = 1;
    for (int i = 3; i < 41; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            cout << 1 << " " << 0 << '\n';
        }
        else if (num == 1) {
            cout << 0 << " " << 1 << '\n';
        }
        else {
            cout << fibonacci[num - 1] << " " << fibonacci[num] << "\n";
        }
    }
}
