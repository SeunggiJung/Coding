#include <string>
#include <vector>

using namespace std;
int N, M;
void revr(vector<vector<int>> &origin, int r){
    for(int i=0;i<M;i++){
        origin[r][i] = origin[r][i] ? 0 : 1;
    }
}
void revc(vector<vector<int>> &origin, int c){
    for(int i=0;i<N;i++){
        origin[i][c] = origin[i][c] ? 0 : 1;
    }
}
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    N = beginning.size();
    M = beginning[0].size();
    int answer = 11;
    for(int i=0;i<(1<<N);i++){
        vector<vector<int>> copy = beginning;
        int cnt = 0;
        for(int j=0;j<N;j++){
            if(i & 1<<j) {
                revr(copy, j);
                cnt++;
            }
        }
        for(int j=0;j<M;j++){
            if(copy[0][j] != target[0][j]){
                revc(copy, j);
                cnt++;
            }
        }
        if(copy == target){
            answer = min(answer, cnt);
        }
    }
    if(answer>10) return -1;
    return answer;
}