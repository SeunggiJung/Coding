#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int S = 0;
	queue<int> stress;
	int s_ache = 0;
	for (int i = 0; i < N; i++) {
		int s;
		cin >> s;
		stress.push(s);
	}
	while (!stress.empty()) {
		int s = stress.front();
		stress.pop();
		S += s;
		if (S < 0) S = 0;
		if (S >= M) s_ache++;
	}
	cout << s_ache;
}
