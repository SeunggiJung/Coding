#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
static vector<pair<char, int>> KS;
void func(int move) {
	int movey[] = {0,0,-1,1,1,1,-1,-1};
	int movex[] = { 1,-1,0,0,1,-1,1,-1 };
	int Kx = KS.front().first + movex[move];
	int Ky = KS.front().second + movey[move];
	int Sx = KS.back().first + movex[move];
	int Sy = KS.back().second + movey[move];
	if (Kx < 65 || Kx>72 || Ky < 49 || Ky>56) return;
	else {
		if (Kx == KS.back().first && Ky == KS.back().second) {
			if (Sx < 65 || Sx>72 || Sy < 49 || Sy>56) return;
			else {
				KS.front().first = Kx;
				KS.front().second = Ky;
				KS.back().first = Sx;
				KS.back().second = Sy;
			}
		}
		else {
			KS.front().first = Kx;
			KS.front().second = Ky;
		}
	}
}
int main() {
	pair<char, int> King, Stone;
	KS = { King, Stone };
	int M;
	string in;
	for (int i = 0; i < 2; i++) {
		cin >> in;
		KS[i] = { in[0],in[1] };
	}
	cin >> M;
	vector<string> moves(M);
	vector<string> move_map = { "R", "L", "B","T","RT","LT","RB","LB" };
	for (int i = 0; i < M; i++) {
		cin >> moves[i];
		func(find(move_map.begin(), move_map.end(), moves[i]) - move_map.begin());
	}
	for (int i = 0; i < 2; i++) {
		cout << KS[i].first << KS[i].second-'0' << "\n";
	}
}