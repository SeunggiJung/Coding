#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int C, N;
vector<string> in;
vector<bool> num(10, false);
vector<pair<long long int, char>> cnt(10, {0,'@'});
set<char> cant;
long long int maxi = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < 10; i++) {
        cnt[i].second = 'A' + i;
    }
    in = vector<string> (N);
    for (int i = 0; i < N; i++) {
        cin >> in[i];
        cant.insert(in[i][0]);
        long long int depth = 1;
        for (int j = in[i].length()-1; j >= 0; j--) {
            cnt[in[i][j] - 'A'].first += depth;
            depth *= 10;
        }
    }
    sort(cnt.begin(), cnt.end());
    long long int sum = 0;
    for (auto c : cnt) {
        for (int i = 0; i < 10; i++) {
            if (num[i]) continue;
            if (i==0 && cant.find(c.second) != cant.end()) continue;
            num[i] = true;
            sum += c.first * i;
            break;
        }
    }
    cout << sum;
}

