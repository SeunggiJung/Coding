#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath> 
using namespace std;
typedef pair<int, int> pii;
int N;
bool compare(const pii& ab1, const pii& ab2) {
        if (!ab1.first) return false; // a=0이면 상대적 후순위
        else if (!ab2.first) return true;
        else if (!ab1.second && !ab2.second) return ab1.first < ab2.first;
        // a!=0인 두 ab를 비교하면 a가 큰 작은 쪽이 후순위
        return ab1.second * ab2.first < ab1.first * ab2.second;
        // a!=0, b!=0인 두 ab를 비교하면 b[i]*a[i+1] < b[i+1]*a[i]를 만족하도록
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<pii> ab(N);
    for (int i = 0; i < N; i++) {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(), ab.end(), compare);
    long long int time = 0;
    for(auto& x : ab){
        time += time * x.first + x.second;
        time %= 40000;
    }
    cout << time;
}