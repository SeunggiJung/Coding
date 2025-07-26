#define _USE_MATH_DEFINES
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int L;
	cin >> L;
	string in;
	cin >> in;
	vector<pair<int, int>> move = { {1,0}, {0,1},{-1,0},{0,-1} };
	int size = 50;
	vector<vector<char>> map(size * 2, vector<char>(size * 2, '#'));
	queue<int> moves;
	pair<int, int> base = { size,size };
	int head = 0;
	int maxx = 0, minx = size, maxy = 0, miny = size;
	map[size][size] = '.';
	for (int i = 0; i < L; i++) {
		char m = in[i];
		if (m == 'R') {
			if (head == 0) head = 4;
			head--;
		}
		if (m == 'L') {
			if (head == 3) head = -1;
			head++;
		}
		if (m == 'F') {
			base.first += move[head].first;
			base.second += move[head].second;
			map[base.first][base.second] = '.';
		}
		if (base.first < miny)miny = base.first;
		if (base.second < minx)minx = base.second;
		if (base.second > maxx)maxx = base.second;
		if (base.first > maxy)maxy = base.first; 
	}
	for (int i = miny; i <= maxy ; i++) {
		for (int j = minx; j <= maxx ; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}
