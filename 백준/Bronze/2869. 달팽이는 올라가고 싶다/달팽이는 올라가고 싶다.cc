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
    int A, B, V;
    cin >> A >> B >> V;
    for (int i = V - A; i < V; i++) {
        if (i % (A - B) == 0) {
            cout << i / (A - B) + 1;
            break;
        }
    }
}