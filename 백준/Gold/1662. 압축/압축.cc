#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
vector<int> v;
int N, M, T;
string s;
pair<int,int> leng(int start) {
    int cnt = 0;
    for (int i = start; i < s.length(); i++) {
        if (s[i] == ')') return { cnt, i };
        if (i + 1 != s.length() && s[i + 1] == '(') {
            cnt += (s[i] - '0') * leng(i + 2).first;
            i = leng(i+2).second;
            continue;
        }
        else cnt += 1;
    }
    return { cnt, 0 };
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    cout << leng(0).first;
}