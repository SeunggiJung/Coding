#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N;
	cin >> N;
	int x, y=0;
	x = N / 5;
	while (true) {
		int sum = 5 * x + 3 * y;
		if (sum == N) break;
		if (sum < N) {
			y++;
		}
		else if (sum > N) {
			x--;
		}
		if (x < 0 || y < 0) {
			cout << -1;
			return 0;
		}
	}
	cout << x + y;
}