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
    
    int N,M;
    cin >> N;
    
    map<int,bool> v;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.insert({ num,true });
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if (v.find(num) != v.end()) cout << 1 << "\n";
        else cout << "0\n";
    }
}