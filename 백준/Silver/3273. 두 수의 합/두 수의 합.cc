#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> in(N);
	vector<bool> is(1000001, false);
	for (int i = 0; i < N; i++) {
		cin >> in[i];
		is[in[i]] = true;
	}
	int x;
	cin >> x;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int h = x - in[i];
		if (h < 0) continue;
		if (h > 1000001)continue;
		if (is[h]) {
			cnt++;
		}
	}
	cout << cnt/2;
}
