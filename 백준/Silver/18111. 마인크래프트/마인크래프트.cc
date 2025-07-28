#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int N, M, B;
	cin >> N >> M >> B;
	int** mine = new int* [N];
	vector<int> values;
	for (int i = 0; i < N; i++) {
		mine[i] = new int[M];
	}
	int max = 0;
	int min = 257;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mine[i][j];
			if (mine[i][j] > max) max = mine[i][j];
			if (mine[i][j] < min)min = mine[i][j];
		}
	}
	int mintime = 99999999;
	int height = 0;
	for (int k = min; k <= max; k++) {
		int b_h = height;
		int hd = 0, ld = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (mine[i][j] > k) {
					hd += mine[i][j] - k;
				}
				else if (mine[i][j] < k) {
					ld += k - mine[i][j];
				}
			}
		}
		if (ld - hd <= B && hd * 2 + ld == mintime && k > b_h) {
			height = k;
		}
		if (ld - hd <= B && hd * 2 + ld < mintime) {
			mintime = hd * 2 + ld;
			height = k;
		}
	}
	cout << mintime << " " << height;
}