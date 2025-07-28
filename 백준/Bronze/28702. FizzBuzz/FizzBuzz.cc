#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string in[3];
    string s;
    int k=0;
    cin >> in[0] >> in[1] >> in[2];
    if (in[0][0] >= '0' && in[0][0] <= '9') {
        int ss = stoi(in[0]) + 3;
        if (ss % 3 == 0) {
            if (ss % 5 == 0) {
                cout << "FizzBuzz\n";
            }
            else
                cout << "Fizz\n";
        }
        else if (ss % 5 == 0)
            cout << "Buzz\n";
        else cout << ss;
    }
    else if (in[1][0] >= '0' && in[1][0] <= '9') {
        int ss = stoi(in[1]) + 2;
        if (ss % 3 == 0) {
            if (ss % 5 == 0) {
                cout << "FizzBuzz\n";
            }
            else
                cout << "Fizz\n";
        }
        else if (ss % 5 == 0)
            cout << "Buzz\n";
        else cout << ss;
    }
    else if (in[2][0] >= '0' && in[2][0] <= '9') {
        int ss = stoi(in[2]) + 1;
        if (ss % 3 == 0) {
            if (ss % 5 == 0) {
                cout << "FizzBuzz\n";
            }
            else
                cout << "Fizz\n";
        }
        else if (ss % 5 == 0)
            cout << "Buzz\n";
        else cout << ss;
    }
}