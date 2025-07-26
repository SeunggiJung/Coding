#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	map<int, string> dict1;
	map<string, int> dict2;
	for (int i = 1; i <= N; i++) {
		string in;
		cin >> in;
		dict1.insert({ i, in });
		dict2.insert({in, i});
	}
	queue<string> input;
	for (int i = 0; i < M; i++) {
		string in;
		cin >> in;
		input.push(in);
	}
	while (!input.empty()) {
		string where = input.front();
		input.pop();
		if (where[0] <= '9') {
			cout << dict1[stoi(where)] << "\n";
		}
		else {
			cout << dict2[where]<< "\n";
		}
	}

}
