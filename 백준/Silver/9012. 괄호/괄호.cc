#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    string out;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        vector<char> v;
        bool flag = false;
        for (int j = 0; j < in.length(); j++) {
            if (in[j] == '(') {
                v.push_back('(');
            }
            else if (in[j] == ')') {
                if (!v.empty())
                    v.pop_back();
                else {
                    flag = true;
                    break;
                }
            }
        }
        if (!v.empty() || flag) out.append("NO\n");
        else out.append("YES\n");
    }
    cout << out;
}