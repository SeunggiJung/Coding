#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());
    int m = 0;
    for (int i = cards.size() - 1; i >= 2; i--) {
        for (int j = i - 1; j >= 1; j--) {
            for (int k = j - 1; k >= 0; k--) {
                if (cards[i] + cards[j] + cards[k] <= M) m = max(m, cards[i] + cards[j] + cards[k]);
            }
        }
    }
    cout << m;
}