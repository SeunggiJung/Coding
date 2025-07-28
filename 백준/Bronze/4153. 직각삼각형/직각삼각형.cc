#include <iostream>
#include <queue>
#include <map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        long long int a[3];
        long long int m = 0;
        long long int sum = 0;
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
            sum += (a[i] * a[i]);
            if (m < a[i]) {
                m = a[i];
            }
        }
        if (!a[0] && !a[1] && !a[2]) break;
        if (sum == m * m * 2) cout << "right\n";
        else cout << "wrong\n";
    }
}