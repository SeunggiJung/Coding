#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0]) return a[0] > b[0];
    return a[1] < b[1];
}
int solution(vector<vector<int>> scores) {
    vector<int> wh = scores[0];
    sort(scores.begin(), scores.end(), cmp);
    int maxi = 0;
    int answer = 0;
    for(auto& score : scores){
        if(score[1] < maxi){
            if(score[0]==wh[0] && score[1]==wh[1]) return -1;
            continue;
        }
        maxi = max(maxi, score[1]);
        if(score[0] + score[1] > wh[0] + wh[1]) answer++;
    }
    return answer+1;
}