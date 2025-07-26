#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, L;
	cin >> N>> L;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int in;
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	bool* visited = new bool[N];
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		cnt++;
		for (int j = i; j < N; j++) {
			int leng = (v[j] + 0.5) - (v[i] - 0.5);
			if (leng <= L) {
				visited[j] = true;
				continue;
			}
			if (leng > L) {
				break;
			}
		}
	}
	cout << cnt;
}