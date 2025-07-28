#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N;
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
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
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (!a) v.pop_back();
        else v.push_back(a);
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    cout << sum;
}