#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, M, x, y;
vector<int> parent;
int find(int child) {
    if (parent[child] == child)
        return child;
    return parent[child] = find(parent[child]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string in;
    cin >> in;
    int index = 0;
    for (int i = 0; i < 12; i++) {
        if (in[i] == '*') index = i;
    }
    int sum = 0;
    for (int i = 0; i < 13; i++) {
        if (i == index) continue;
        if (i % 2 == 1) sum += 2 * (in[i] - '0');
        sum += (in[i] - '0');
    }
    sum %= 10;
    int answer = (10 - sum)%10;
    if (index % 2 == 1) {
        if (answer == 1) answer = 7;
        else if (answer == 2) answer = 4;
        else if (answer == 4) answer = 8;
        else if (answer == 5)answer = 5;
        else if (answer == 7) answer = 9;
        else if (answer == 8)answer = 6;
        else answer /= 3;
        
    }
    cout << answer;
}