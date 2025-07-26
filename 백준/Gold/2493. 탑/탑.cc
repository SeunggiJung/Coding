#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> tower(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> tower[i];
    vector<int> dec = { 0 };
    vector<int> see(N + 1, 0);
    int tall = 0;
    for (int i = 1; i <= N; i++) {
        while (tower[dec.back()] <= tower[i]) {
            dec.pop_back();
            if (dec.empty()) break;
        }
        if(!dec.empty()) see[i] = dec.back();
        dec.push_back(i);
    }
    for (int i = 1; i <= N; i++) cout << see[i] << " ";
}