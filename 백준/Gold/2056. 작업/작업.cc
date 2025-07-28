#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<pair<int, queue<int>>> v(N);
	vector<int> times(N);
	for (int i = 0; i < N; i++) {
		int time, k;
		cin >> time >> k;
		queue<int> x;
		for (int j = 0; j < k; j++) {
			int sh;
			cin >> sh;
			x.push(sh);
		}
		v[i] = { time,x };
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		int t = v[i].first;
		queue<int> sh = v[i].second;
		if (sh.empty()) {
			times[i] = t;
		}
		else {
			int large = 0;
			int wh = 0;
			while (!sh.empty()) {
				int x = sh.front();
				sh.pop();
				if (large < times[x - 1]) {
					large = times[x - 1];
					wh = x - 1;
				}
			}
			times[i] = times[wh] + t;
		}
		if (max < times[i])max = times[i];
	}
	cout << max;
	
}

