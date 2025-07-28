#include "iostream"
#include <queue>
using namespace std;
static int* s;
static bool visited;
void bfs(int n, int k, int time) {
	queue<int> q;
	q.push(n);
	int pos;
	while (!q.empty()) {
		pos = q.front();
		if (pos == k) {
			cout << s[pos];
			return;
		}
		q.pop();
		int d[3] = { pos,1,-1 };
		int t[3] = { 0,1,1 };
		for (int i = 0; i < 3; i++) {
			int n_pos = pos + d[i];
			if (n_pos<0 || n_pos>100001) continue;
			if (s[n_pos] > s[pos] + t[i]) {
				q.push(n_pos);
				s[n_pos] = s[pos] + t[i];
			}
		}
	}
}
int main() {
	int N, K, time = 0;
	cin >> N >> K;
	s = new int[100001];
	for (int i = 0; i < 100001; i++) {
		s[i] = 999999;
	}
	s[N] = 0;
	bfs(N, K, time);
}