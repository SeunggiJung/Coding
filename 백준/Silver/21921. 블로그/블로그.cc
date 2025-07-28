#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main() {
	int N, X;
	cin >> N >> X;
	vector<int> in(N), nj(N+X);
	for (int i = 0; i < N; i++) {
		cin >> in[i];
		nj[i] += in[i];
		if (i > 0) nj[i] += nj[i - 1];
		if (i >= X) nj[i] -= in[i - X];
	}
	sort(nj.rbegin(), nj.rend());
	if (!nj.front()) cout << "SAD";
	else {
		int cnt = 1;
		int max = nj.front();
		while (true) {
			if (nj[cnt] == max) cnt++;
			else break;
		}
		cout << nj.front() << "\n" << cnt;
	}
}

