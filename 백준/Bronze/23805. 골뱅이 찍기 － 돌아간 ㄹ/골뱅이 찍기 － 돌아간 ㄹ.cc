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
    int N;
    cin >> N;
    vector<vector<char>> v(N*5, vector<char>(N * 5, '@'));
    for (int i = N; i < N + N; i++) {
        for (int j = N; j < v.size(); j++) {
            v[j][i] = ' ';
        }
    }
    for (int i = N*3; i < N*4; i++) {
        for (int j = 0; j < v.size()-N; j++) {
            v[j][i] = ' ';
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
}