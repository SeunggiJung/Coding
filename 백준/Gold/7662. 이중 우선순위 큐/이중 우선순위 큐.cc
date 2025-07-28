#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    while (N-- > 0) {
        cin >> M;
        map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> asc;
        priority_queue<int> des;
        for (int i = 0; i < M; i++)
        {
            char order;
            int num;
            cin >> order >> num;
            if (order == 'I') {
                asc.push(num);
                des.push(num);
                if (!m[num]) m[num] = 0;
                m[num]++;
            }
            else {
                if (num == 1) {
                    while (!des.empty()) {
                        int n = des.top();
                        des.pop();
                        if (!m[n]) continue;
                        m[n]--;
                        break;
                    }
                }
                else {
                    while (!asc.empty()) {
                        int n = asc.top();
                        asc.pop();
                        if (!m[n]) continue;
                        m[n]--;
                        break;
                    }
                }
            }
        }
        bool f1=false, f2=false;
        int maxi, mini;
        while (!des.empty()) {
            int n = des.top();
            des.pop();
            if (!m[n]) {
                continue;
            }
            f1 = true;
            maxi = n;
            break;
        }
        while (!asc.empty()) {
            int n = asc.top();
            asc.pop();
            if (!m[n]) continue;
            f2 = true;
            mini = n;
            break;
        }
        if (f1 && f2) cout << maxi << " " << mini << "\n";
        else cout << "EMPTY\n";
    }
}