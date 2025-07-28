#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
static lli N, M, K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    map<int, bool> m;
    for (int i = 0;i < N;i++) {
        int a;
        cin >> a;
        m[a] = true;
    }
    cin >> M;
    for (int i = 0;i < M;i++) {
        int in;
        cin >> in;
        if (m[in]) cout << "1 ";
        else cout << "0 ";
    }

}