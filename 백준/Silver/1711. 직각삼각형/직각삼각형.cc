#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> pll;
static int N, M, K;
vector<int> v;
map<int, lli> m;
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
    vector<pll> v(N);
    vector<vector<lli>> dist(N, vector<lli>(N, 0));
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        for (int j = 0; j < i; j++) {
            dist[i][j] = powl(v[i].first - v[j].first, 2) + powl(v[i].second - v[j].second, 2);
            dist[j][i] = powl(v[i].first - v[j].first, 2) + powl(v[i].second - v[j].second, 2);
        } 
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                lli a, b, c, l;
                a = dist[i][j];
                b = dist[j][k];
                c = dist[k][i];
                l = max({ a,b,c });
                if (a + b + c == 2 * l) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}