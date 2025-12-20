#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> servers(25, 0);
    for(int i=0;i<24;i++){
        int player = players[i];
        int req = player / m;
        if(servers[i] < req){
            int expands = req - servers[i];
            for(int j=0;j<k;j++){
                if(i+j>24) continue;
                servers[i+j] += expands;
            }
            answer += expands;
        }
    }
    return answer;
}