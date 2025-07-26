#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
int N;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> inc;
    priority_queue<int> dec;
    inc.push(10001);
    dec.push(-10001);
    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;
        if (input >= dec.top()) inc.push(input);
        else dec.push(input);
        if (dec.size() == inc.size() + 2) {
            inc.push(dec.top());
            dec.pop();
        }
        if (inc.size() > dec.size()) {
            dec.push(inc.top());
            inc.pop();
        }
        cout << dec.top() << "\n";
    }
}