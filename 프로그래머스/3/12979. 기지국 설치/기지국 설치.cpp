#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int cur=1;
    for(int x : stations){
        int length = x-w-cur;
        answer += (length+2*w) / (2*w+1);
        cur = x + w + 1;
    }
    int length = n - cur + 1;
    answer += (length+2*w) / (2*w+1);
    return answer;
}