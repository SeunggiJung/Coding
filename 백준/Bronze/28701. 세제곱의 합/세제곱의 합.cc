#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
static long long int sum;
static long long int N, M;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    int sum1=0, sum2=0, sum3=0;
    for (int i = 1; i <= N; i++) {
        sum1 += i;
        sum3 += i * i * i;
    }
    cout << sum1 << "\n" << sum1*sum1 << "\n" << sum3;
}