#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    if (s.length() <= 1) {
        cout << s << '\n';
        return 0;
    }
    deque<char> dq;
    dq.push_back(s[0]);

    for (int i = 1; i < s.length(); ++i) {
        char cur = s[i];
        if (cur <= dq.front()) {
            dq.push_front(cur);
        } else {
            dq.push_back(cur);
        }
    }

    for (char c : dq) {
        cout << c;
    }
}
