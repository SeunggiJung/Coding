#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	int cnt = 0;
	int f = 0, n = N;
	while (true) {
		if (n / 5 >= 1) {
			f++;
			n = n / 5;
		}
		if (n / 5 == 0) break;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= f; j++) {
			if (i % (int)pow(5, j) == 0)
				cnt = cnt + 1;
		}
	}
	cout << cnt;
}
