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
static int N, M, K;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    set<string> s;
    for (int i = 0; i < N; i++) {
        cin >> K;
        string tmp;
        string str = "";
        for (int j = 0; j < K; j++) {
            cin >> tmp;
            str += "-" + tmp;
            s.insert(str);
        }
    }
    for (auto& x : s) {
        int cnt = count(x.begin(), x.end(), '-');
        int pos=0;
        for (int i = x.length() - 1; i > 0; i--) 
            if (x[i] == '-') {
                pos = i;
                break;
            }
        string a = x.substr(pos + 1);
        for (int i = 0; i < cnt-1; i++)cout << "--";
        cout << a << "\n";
    }
}