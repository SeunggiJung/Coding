#include <iostream>
#include <queue>
#include <map>
using namespace std;
static int minimum;
int main() {
	string in;
	cin >> in;
	bool java = false;
	bool cpp = false;
	queue<int> q;
	for (int i = 0; i < in.length(); i++) {
		if (isupper(in[i])) { 
			java = true;
			q.push(i);
		}
		if (in[i] == '_') {
			cpp = true;
			q.push(i);
		}
	}
	if (java && cpp)goto end;
	if (!java && !cpp) {
		cout << in;
		return 0;
	}
	if (java) {
		int cnt = 0;
		while (!q.empty()) {
			int x = q.front();
			x = x + cnt;
			if (x == 0) goto end;
			q.pop();
			in[x] |= 32;
			in.insert(x, "_");
			cnt++;
		}
		cout << in;
		return 0;
	}
	if(cpp) {
		int cnt = 0;
		while (!q.empty()) {
			int x = q.front();
			x = x - cnt;
			if (x == 0) goto end;
			if (!isalpha(in[x+1])) goto end;
			if (x + 1 == in.length()) goto end;
			q.pop();
			in[x + 1] -= 32;
			in.erase(x, 1);
			cnt++;
		}
		cout << in;
		return 0;
	}
	end:
	cout << "Error!";
	
}