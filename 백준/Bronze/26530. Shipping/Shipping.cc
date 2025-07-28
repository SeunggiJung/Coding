#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
static long long int sum;
static int N, M;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        double sum = 0;
        for (int i = 0; i < N; i++) {
            string a;
            int b;
            double c;
            cin >> a >> b >> c;
            sum += b * c;
        }
        printf("$%.2f\n", sum);
    }
}