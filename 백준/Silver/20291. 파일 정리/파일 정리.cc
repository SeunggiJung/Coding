#include <iostream>
#include <string>
#include <map>
using namespace std;
static int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    map<string, int> m;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < in.length(); j++) {
            if (in[j] == '.') {
                string ext = in.substr(j + 1, in.length() - j - 1);
                if (!m[ext]) m[ext] = 0;
                m[ext]++;
            }
        }
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " " << iter->second << "\n";
    }
}