#include <iostream>
using namespace std;
int main() {
	int in;
	long long int out = 1;
	cin >> in;
	for (int i = 1; i <= in; i++) {
		out *= i;
	}
	cout << out;
}