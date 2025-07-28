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
    string in;
    cin >> in;
    if (in[0] == 'E')cout << "I";
    else cout << "E";
    if (in[1] == 'N')cout << "S";
    else cout << "N";
    if (in[2] == 'F')cout << "T";
    else cout << "F";
    if (in[3] == 'P')cout << "J";
    else cout << "P";
}