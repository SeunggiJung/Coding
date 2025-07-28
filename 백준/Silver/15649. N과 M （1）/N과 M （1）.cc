#include <iostream>
#include <string>
using namespace std;

static int N, M;
static bool* list = new bool[N];
static int* out = new int[N];
string os = "";
void sy(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << out[i] << " ";
		}
		cout << "\n";
		count = 0;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!list[i]) {
			list[i] = true;
			out[count] = i + 1;
			sy(count+1);
			list[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) list[i] = false;
	sy(0);
}
