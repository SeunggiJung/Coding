#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;
typedef unsigned long long int lli;
typedef pair<lli, lli> pll;
static int N;
static lli M;
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
    map<string, int> m1;
    map<string, int> m2;
    vector<string> v(N);
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        m1[in] = i;
        m2[in] = i;
        v[i] = in;
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        if (m1[in] > i) {
            cnt++;
            for (int j = 0; j < m2[in]; j++) {
                m1[v[j]]++;
            }
        }
    }
    cout << cnt;
}