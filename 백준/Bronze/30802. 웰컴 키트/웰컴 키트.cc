#include <iostream>
#include <queue>
#include <map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    int Ts[6];
    for (int i = 0; i < 6; i++) {
        cin >> Ts[i];
    }
    int T, P;
    cin >> T >> P;
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        cnt += Ts[i] / T + 1;
        if (Ts[i] % T == 0) cnt--;
    }
    cout << cnt << "\n";
    cout << N / P << " " << N % P;
}