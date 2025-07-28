#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<char> v;
void printall() {
    while (!v.empty()) {
        cout << v.back();
        v.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string in;
    getline(cin, in);
    bool taged = false;
    int cnt = 0;
    
    for (char c : in) {
        if (!taged && c == ' ') {
            printall();
            cout << ' ';
            continue;
        }
        if (c == '<') {
            if (!v.empty()) {
                printall();
            }
            taged = true;
        }
        if (taged) cout << c;
        else v.push_back(c);
        if (c == '>')taged = false;
    }
    
    printall();
}
