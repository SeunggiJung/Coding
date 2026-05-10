#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<unordered_set<int>> s(9);

    int base = 0;
    for (int i = 1; i <= 8; i++) {
        base = base * 10 + N;
        s[i].insert(base);
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (int x : s[j]) {
                for (int y : s[i - j]) {
                    s[i].insert(x + y);
                    s[i].insert(x - y);
                    s[i].insert(x * y);
                    if (y != 0) s[i].insert(x / y);
                }
            }
        }
        if (s[i].count(number)) return i;
    }

    return -1;
}