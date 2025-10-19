#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<vector<int>> AtoB;
vector<int> give;
vector<int> take;
map<string, int> index;
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int N = friends.size();
    AtoB = vector<vector<int>> (N, vector<int>(N, 0));
    give = vector<int> (N,0);
    take = vector<int> (N,0);
    int i=0;
    for(auto name : friends){
        index[name] = i;
        i+=1;
    }
    for(auto gift : gifts){
        string A,B;
        stringstream ss(gift);
        ss>>A>>B;
        int a = index[A];
        int b = index[B];
        give[a]++;
        take[b]++;
        AtoB[a][b]++;
    }
    vector<int> will(N,0);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(i==j) continue;
            int gi = give[i] - take[i];
            int gj = give[j] - take[j];
            if(AtoB[i][j]>AtoB[j][i]) {
                will[i]++;
            }
            else if (AtoB[i][j]<AtoB[j][i]){
                will[j]++;
            }
            else {
                if(gi>gj) will[i]++;
                else if(gi<gj) will[j]++;
            }
            answer = max(answer, will[i]);
        }
    }
    return answer;
}