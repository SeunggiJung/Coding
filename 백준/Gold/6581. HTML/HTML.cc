#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
static int N, M, L;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string word;
    int cnt = 0;
    while (cin>>word) {
        if (word == "<br>") {
            cout << "\n"; cnt = 0;
        }
        else if (word == "<hr>") {
            if (cnt) {
                cnt = 0; cout << "\n";
            }
            for (int i = 0; i < 80; i++) {
                cout << "-";
            }
            cout << "\n";
        }
        else {
            if (cnt + word.size() + 1 > 80) { cnt = 0; cout << "\n"; }
            if (cnt) { cout << " "; cnt++; }
            cout << word;
            cnt += word.size();
        }
    }
}