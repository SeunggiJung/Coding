#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int, vector<int>> pq;
    for(auto& a : works){
        pq.push(a);
    }
    int cnt = 0;
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        x--;
        cnt++;
        if(x) pq.push(x);
        if(cnt==n) break;
    }
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        answer += x*x;
    }
    return answer;
}