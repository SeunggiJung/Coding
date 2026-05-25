#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
        vector<vector<int>> wl;
        wl.assign(n+1, vector<int>(n+1, 0));
        for(auto& r : results){
            wl[r[0]][r[1]] = 1;
            wl[r[1]][r[0]] = -1;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(wl[i][k]==1 && wl[k][j]==1){
                        wl[i][j] = 1;
                        wl[j][i] = -1;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            bool flag = true;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(!wl[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag) answer++;
        }
        return answer;
}