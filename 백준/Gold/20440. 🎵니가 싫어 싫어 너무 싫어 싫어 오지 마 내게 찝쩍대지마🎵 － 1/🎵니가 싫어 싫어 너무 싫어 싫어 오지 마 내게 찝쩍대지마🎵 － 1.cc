#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
map<int, int> entrytime;
int N;
struct compare {
    bool operator()(const pii& a, const pii& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<int, vector<int>, greater<int>> end;
    cin >> N;
    vector<pii> input(N);
    for (int i = 0; i < N; i++) {
        int Te, Tx;
        cin >> Te >> Tx;
        input[i] = { Te,Tx };
    }
    sort(input.begin(), input.end());
    int maxi = 0;
    int s=0, e=0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int enter = input[i].first;
        int exit = input[i].second;
        while (!end.empty() && enter >= end.top()) {
            end.pop();
        }
        end.push(exit);
        cnt = end.size();
        if (cnt > maxi) {
            maxi = cnt;
            s = enter;
            e = end.top();
        }
        if (cnt == maxi) {
            if (e == enter) {
                e = end.top();
            }
        }
    }
    cout << maxi << "\n" << s << " " << e;
}