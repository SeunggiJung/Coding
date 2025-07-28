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
    string in;
    cin >> in;
    vector<char> v;
    for (int i = 0; i < in.length(); i++) {
        int s = v.size();
        v.push_back(in[i]);
        if (s + 1 < 4 || v.back() == 'A') continue;
        if (v[s - 3] == 'P' && v[s - 2] == 'P' && v[s - 1] == 'A') {
            for (int j = 0; j < 4; j++) v.pop_back();
            v.push_back('P');
        }
    }
    if (v.size() == 1 && v[0]=='P') cout << "PPAP";
    else cout << "NP";
}