#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        string in;
        getline(cin, in);
        if (in == ".") break;
        vector<char> v;
        bool flag = true;
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == '(' || in[i] == '[') v.push_back(in[i]);
            if (in[i] == ')') {
                if (v.size() && v.back() == '(')
                    v.pop_back();
                else flag = false;
            }
            if (in[i] == ']') {
                if (v.size() && v.back() == '[')
                    v.pop_back();
                else flag = false;
            }
        }
        if (v.size() || !flag) cout << "no\n";
        else cout << "yes\n";
    }
}