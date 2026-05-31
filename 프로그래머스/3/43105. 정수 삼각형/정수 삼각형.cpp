#include <string>
#include <vector>

using namespace std;
vector<vector<int>> dp;
vector<vector<int>> triangle;
int height;
int bt(int depth, int cur){
    if(dp[depth][cur]) return dp[depth][cur];
    if(depth==height) return dp[depth][cur] = triangle[depth][cur];
    return dp[depth][cur] = max(triangle[depth][cur] + bt(depth+1, cur), 
                                triangle[depth][cur] + bt(depth+1, cur+1));
}
int solution(vector<vector<int>> triangle1) {
    dp.assign(500, vector<int>(500, 0));
    triangle = triangle1;
    int answer = 0;
    height = triangle.size()-1;
    bt(0, 0);
    return dp[0][0];
}