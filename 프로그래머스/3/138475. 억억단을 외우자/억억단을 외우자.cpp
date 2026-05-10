#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> cnt(e+1, 1);
    for(int i=2;i<=e+1;i++){
        for(int j=i;j<=e+1;j+=i){
            cnt[j]++;
        }
    }
    vector<int> maxi(e+1, 0);
    int m = cnt[e];
    maxi[e] = e;
    for(int i=e-1;i>=0;i--){
        if(cnt[i]>=m){
            m = cnt[i];
            maxi[i] = i;
        }else{
            maxi[i] = maxi[i+1];
        }
    }
    vector<int> answer;
    for(int s : starts){
        answer.push_back(maxi[s]);
    }
    return answer;
}