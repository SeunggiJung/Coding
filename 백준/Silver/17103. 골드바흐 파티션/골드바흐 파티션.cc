#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	queue<int> Ns;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		Ns.push(N);
	}
	while (!Ns.empty()) {
		int N = Ns.front();
		Ns.pop();
		int cnt = 0;
		vector<bool> v(N+1, true);
		v[0] = false;
		v[1] = false;
		for (int i = 2; i <= sqrt(N); i++) {
			if (v[i] == true) {
				for (int j = 2; i * j <= N; j++) {
					v[i * j] = false;
				}
			}
		}
		for (int i = 2; i <= N/2; i++) {
			if (v[i] && v[N - i]) cnt++;
		}
		cout << cnt << "\n";
	}
}
