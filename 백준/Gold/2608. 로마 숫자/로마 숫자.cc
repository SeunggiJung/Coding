#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <map>;
using namespace std;
static int N;
map<char, int> index;
map<char, int> value;
map<int, bool> visited;
map<int, string> vtos;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    index['I'] = 0; value['I'] = 1;
    index['V'] = 1; value['V'] = 5;
    index['X'] = 2; value['X'] = 10;
    index['L'] = 3; value['L'] = 50;
    index['C'] = 4; value['C'] = 100;
    index['D'] = 5; value['D'] = 500;
    index['M'] = 6; value['M'] = 1000;
    vector<string> s(2);
    vector<int> v;
    v = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
    vtos[1000] = "M"; vtos[900] = "CM"; vtos[500] = "D"; vtos[400] = "CD"; vtos[100] = "C"; vtos[90] = "XC"; 
    vtos[50] = "L"; vtos[40] = "XL"; vtos[10] = "X"; vtos[9] = "IX"; vtos[5] = "V"; vtos[4] = "IV"; vtos[1] = "I";
    cin >> s[0] >> s[1];
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < s[i].length()-1; j++) {
            if (index[s[i][j]] < index[s[i][j + 1]]) sum -= value[s[i][j]];
            else sum += value[s[i][j]];
        }
        sum += value[s[i].back()];
    }
    cout << sum<<"\n";
    while (sum>0) {
        for (int i = 0; i < v.size(); i++) {
            if (sum < v[i])continue;
            if (i % 2 == 0) {
                int div = sum / v[i];
                sum = sum % v[i];
                for (int j = 0; j < div; j++)cout << vtos[v[i]];
            }
            else {
                if (visited[i]) continue;
                sum -= v[i];
                visited[i / 4 * 4 + 1] = true;
                visited[i / 4 * 4 + 3] = true;
                cout << vtos[v[i]];
            }
        }
    }
}
