#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    queue<int> q;
    vector<int> out;
    for (int i = 0; i < N; i++) {
        string command;
        int num;
        cin >> command;
        if (command == "push") {
            cin >> num;
            q.push(num);
        }
        else if (command == "pop") {
            if (q.empty()) out.push_back(-1);
            else {
                out.push_back(q.front());
                q.pop();
            }
        }
        else if (command == "size")
            out.push_back(q.size());
        else if (command == "empty")
            out.push_back(q.empty());
        else if (command == "front") {
            if (q.empty()) out.push_back(-1);
            else out.push_back(q.front());
        }
        else if (command == "back") {
            if (q.empty()) out.push_back(-1);
            else out.push_back(q.back());
        }
    }
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << "\n";
    }
}