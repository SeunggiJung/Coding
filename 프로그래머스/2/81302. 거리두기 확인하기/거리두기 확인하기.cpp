#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int solve(vector<pii> p, vector<string> place){
    for(auto& x : p){
        for(int i=0;i<4;i++){
            int nr = x.first + dr[i];
            int nc = x.second + dc[i];
            if(nr<0||nc<0||nr>=5||nc>=5) continue;
            if(place[nr][nc]=='P') return 0;
            if(place[nr][nc]=='X') continue;
            if(place[nr][nc]=='O'){
                for(int j=0;j<4;j++){
                    int nnr = nr + dr[j];
                    int nnc = nc + dc[j];
                    if(nnr<0||nnc<0||nnr>=5||nnc>=5) continue;
                    if(place[nnr][nnc]=='X') continue;
                    if(place[nnr][nnc]=='P' && (nnr!=x.first || nnc!=x.second)) return 0;
                }
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto& place : places){
        vector<pii> p;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(place[i][j]=='P') p.push_back({i,j});
            }
        }
        answer.push_back(solve(p, place));
    }
    
    return answer;
}