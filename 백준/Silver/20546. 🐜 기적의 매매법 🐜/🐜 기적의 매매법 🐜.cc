#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int cash_j, cash_s;
	int j_j=0, j_s=0;
	cin >> cash_j;
	cash_s = cash_j;
	vector<int> juga;
	for (int i = 0; i < 14; i++) {
		int j;
		cin >> j;
		juga.push_back(j);
	}
	int today;
	for (int i = 0; i < 3;i++) {
		today = juga[i];
		j_j += cash_j / today;
		cash_j = cash_j % today;
	}
	for (int i = 3; i < 14; i++) {
		today = juga[i];
		j_j += cash_j / today;
		cash_j = cash_j % today;
		if (juga[i-3]<juga[i - 2] &&juga[i-2] < juga[i - 1]&& juga[i-1]< juga[i]) {
			cash_s += today * j_s;
			j_s = 0;
		}
		if (juga[i-3]>juga[i - 2] &&juga[i-2] > juga[i - 1]&&juga[i-1] > juga[i]) {
			j_s += cash_s / today;
			cash_s = cash_s % today;
		}
	}
	if (cash_j + j_j * today > cash_s + j_s * today) cout << "BNP";
	else if (cash_j + j_j * today < cash_s + j_s * today)cout << "TIMING";
	else cout << "SAMESAME";
}