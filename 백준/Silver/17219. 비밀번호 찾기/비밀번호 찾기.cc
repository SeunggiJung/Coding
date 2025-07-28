#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	map<string, string> m;
	for (int i = 0; i < N; i++) {
		string key, value;
		cin >> key >> value;
		m.insert({ key, value });
	}
	queue<string> q;
	for (int i = 0; i < M; i++) {
		string f;
		cin >> f;
		q.push(f);
	}
	while (!q.empty()) {
		cout << m[q.front()] << "\n";
		q.pop();
	}
}
