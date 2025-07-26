#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        start:
        string in;
        cin >> in;
        if (in == "0") break;
        int len = in.length();
        for (int i = len / 2; i < len; i++) {
            if (in[i] != in[len - i - 1]) {
                cout << "no\n";
                goto start;
            }
        }
        cout << "yes\n";
    }
}