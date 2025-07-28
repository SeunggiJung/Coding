#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
static int N, M, T;

struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;
        cin >> N;
        map<char, int> cnt;
        int mini = INT32_MAX;
        int maxi = 0;
        vector<queue<int>> v(26);
        bool flag = false;
        for (int j = 0; j < str.length();j++) {
            char c = str[j];
            if (!cnt[c]) cnt[c] = 0;
            cnt[c]++;
            v[c - 'a'].push(j);
            if (cnt[c] == N) {
                flag = true;
                int leng = v[c - 'a'].back() - v[c - 'a'].front() + 1;
                mini = min(leng, mini);
                maxi = max(leng, maxi);
                v[c - 'a'].pop();
                cnt[c]--;
            }
        }
        if (flag) {
            cout << mini << " " << maxi << "\n";
        }
        else cout << "-1\n";
    }
}