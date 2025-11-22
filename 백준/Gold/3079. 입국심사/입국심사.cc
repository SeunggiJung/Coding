#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, M;
vector<long long> test;
long long Test(long long left, long long right, long long rst)
{
	if (left > right) return rst;
	long long mid = (left + right) / 2;

	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (mid / test[i]);
		if (sum >= M) return Test(left, mid - 1, mid);
	}
	return Test(mid + 1, right, rst);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	test.resize(N);
	long long Max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> test[i];
		Max = max(Max, test[i]);
	}
	long long end = Max * M;
	cout << Test(1, end, end) << '\n';
}