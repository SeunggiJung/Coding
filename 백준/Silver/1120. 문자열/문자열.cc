#include <iostream>
#include <string>
using namespace std;
int diff(string x, string y) {
	int cnt = 0;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] != y[i]) cnt++;
	}
	return cnt;
}
int main() {
	string X, Y;
	cin >> X >> Y;
	int cnt = 99;
	int xlen = X.length();
	int ylen = Y.length();
	if (!X.compare(Y)) {
		cnt = 0;
	}
	if (xlen == ylen) {
		cnt = diff(X,Y);
	}
	else {
		for (int i = 0; i <= ylen - xlen; i++) {
			string y = Y.substr(i, xlen);
			if (diff(X, y) < cnt) cnt = diff(X, y);
		}
	}
	cout << cnt;
} 
