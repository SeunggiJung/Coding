#include <iostream>
#include <vector>
#include <map>
#include <cmath> 
using namespace std;
typedef pair<long long int, long long int> pll;
int N;
map<int, int> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> v(N + 1);
    vector<int> arr;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= N; i++) {
        int index = lower_bound(arr.begin(), arr.end(), v[i]) - arr.begin();
        if (index == arr.size()) arr.push_back(v[i]);
        else arr[index] = v[i];
    }
    cout << N - arr.size();
}