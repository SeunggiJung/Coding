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
    vector<int> v;
    vector<int> out;
    for (int i = 0; i < N; i++) {
        string command;
        int num;
        cin >> command;
        if (command == "push") {
            cin >> num;
            v.push_back(num);
        }
        else if (command == "pop") {
            if (v.empty()) out.push_back(-1);
            else {
                out.push_back(v.back());
                v.pop_back();
            }
        }
        else if (command == "size")
            out.push_back(v.size());
        else if (command == "empty")
            out.push_back(v.empty());
        else if (command == "top") {
            if (v.empty()) out.push_back(-1);
            else out.push_back(v.back());
        }
    }
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << "\n";
    }
}