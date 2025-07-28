#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main() {
	int N;
	cin >> N;
	int B = N;
	vector<int> in(N);
	vector<int> grade(N);
	long long int boolman = 0;
	int m = 0;
	for (int i = 0; i < N; i++) {
		cin >> in[i];
		m = max(in[i], m);
	}
	sort(in.rbegin(), in.rend());
	for (int i = 0; i < N; i++) {
		boolman += abs(in[i] - B--);
	}
	cout << boolman;
}
