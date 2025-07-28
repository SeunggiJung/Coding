#include "iostream"
using namespace std;

int main() {
	int A, B, C, M;
	cin >> A >> B >> C >> M;
	int stress = 0, time = 0, work = 0;
	if (A > M) goto end;
	for (int i = 0; i < 24; i++) {
		if (stress + A > M) {
			stress -= C;
			if (stress < 0) stress = 0;
		}
		else if (stress + A <= M) {
			stress += A;
			work += B;
		}
	}
	end:
	cout << work;
}