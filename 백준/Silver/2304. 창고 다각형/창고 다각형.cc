#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
static int N, M, T;
//vector<int> v;
map<int, ll> m;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    int max_index=0, max_h=0;
    vector<int> v(1001, 0);
    for (int i = 0; i < T; i++) {
        int x=0;
        cin >> x;
        cin >> v[x];
        if (v[x] > max_h) {
            max_h = v[x];
            max_index = x;
        }
    }
    int H = 0;
    int area = 0;
    for (int i = 1; i < max_index; i++) {
        H = max(H, v[i]);
        area += H;
    }
    H = 0;
    for (int i = 1000; i > max_index; i--) {
        H = max(H, v[i]);
        area += H;
    }
    cout << area + max_h;
}