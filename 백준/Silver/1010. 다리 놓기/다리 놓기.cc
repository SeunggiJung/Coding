#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
long long int func(int start, int end) {
	long long int result = 1;
	for (int i = start; i <= end; i++) {
		result *= i;
	}
	return result;
}
int main() {
	int T;
	cin >> T;
	queue<pair<int, int>> q;
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		q.push({ N,M });
	}
	while (!q.empty()) {
		int n, r;
		n = q.front().second;
		r = q.front().first;
		r = r > (n / 2) ? n-r : r;
		cout << func(n-r+1, n) / func(1, r) << "\n";
		q.pop();
	}
}