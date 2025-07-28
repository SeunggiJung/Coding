#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> in(9);
    int sum = 0;
    for (int i = 0; i < 9; i++)
        {cin >> in[i];sum += in[i];}
    int diff = sum - 100;
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            if (i == j)continue;
            if (in[i] + in[j] == diff) {
                in[i] = 0;
                in[j] = 0;
                goto a;
            }
        }
    }
    a:
    sort(in.begin(), in.end());
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 0)continue;
        cout << in[i] << "\n";
    }
}