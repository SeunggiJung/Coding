#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int s = money.size();
    vector<int> dp1(s, 0);
    vector<int> dp2(s, 0);
    dp1[0] = dp1[1] = money[0];
    dp2[1] = money[1];
    for(int i=2;i<s;i++){
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }
    return max(dp1[s-2], dp2[s-1]);
}