#define _USE_MATH_DEFINES
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N), B(M);
	for (int i = 0; i < 2; i++) {
		switch (i) {
		case 0:
			for (int j = 0; j < N; j++) {
				cin >> A[j];
			}
			break;
		case 1:
			for (int j = 0; j < M; j++) {
				cin >> B[j];
			}
			break;
		}
	}
	for (int i = 0; i < M; i++) {
		A.push_back(B[i]);
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
}
