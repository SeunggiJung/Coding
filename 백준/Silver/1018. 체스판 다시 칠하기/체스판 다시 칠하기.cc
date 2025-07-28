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
static long long int N, M;
static vector<vector<char>> v;
static vector<bool> visited;
static int cnt;
map<int, vector<int>> m;
static int maxi;
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
    vector<vector<char>> wb1(8, vector<char>(8));
    vector<vector<char>> wb2(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                wb1[i][j] = 'W';
                wb2[i][j] = 'B';
            }
            else {
                wb1[i][j] = 'B';
                wb2[i][j] = 'W';
            }
        }
    }
    v = vector<vector<char>>(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }
    maxi = 999999999;
    for (int i = 0; i < N - 7; i++) {
        for (int j = 0; j < M - 7; j++) {
            int cnt1 = 0;
            int cnt2 = 0;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (v[i + k][j + l] != wb1[k][l])
                        cnt1++;
                    if (v[i + k][j + l] != wb2[k][l]) {
                        cnt2++;
                    }
                }
            }
            maxi = min(maxi, cnt1);
            maxi = min(maxi, cnt2);
        }
    }
    cout << maxi;
}
