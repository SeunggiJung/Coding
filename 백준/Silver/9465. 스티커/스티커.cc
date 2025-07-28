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
static long long int N, T;
static vector<vector<int>> v;
static vector<vector<int>> v2;
static vector<vector<bool>> visited;
static int cnt;
map<int, vector<int>> m;
static int maxi;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int sum = 0;
        v = vector<vector<int>>(2, vector<int>(N));
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < N; k++) {
                cin >> v[j][k];
            }
        }
        maxi = 0;
        if (N == 1) {
            maxi = max(v[0][0], v[1][0]);
        }
        else {
            v2 = vector<vector<int>>(2, vector<int>(N, 0));
            v2[0][0] = v[0][0];
            v2[1][0] = v[1][0];
            v2[0][1] = v[1][0] + v[0][1];
            v2[1][1] = v[1][1] + v[0][0];
            for (int k = 2; k < N; k++) {
                v2[0][k] = max(v2[1][k - 1], v2[1][k - 2]) + v[0][k];
                v2[1][k] = max(v2[0][k - 1], v2[0][k - 2]) + v[1][k];
            }
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < N; k++) {
                    maxi = max(maxi, v2[j][k]);
                }
            }
        }
        cout << maxi << "\n";
    }
    
}
