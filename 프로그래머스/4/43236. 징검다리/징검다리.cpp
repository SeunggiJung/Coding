#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    int answer = 0;
    int left = 1;
    int right = distance;
    while(left+1<right){
        int mid = (left + right) / 2;
        int bef = 0;
        int cnt = 0;
        for(auto& rock : rocks){
            if(rock - bef < mid){
                cnt++;
                continue;
            }
            bef = rock;
        }
        if(cnt>n) right = mid;
        else{
            left = mid;
        }
    }
    int bef = 0;
    int cnt = 0;
    for(auto& rock : rocks){
        if(rock - bef < right){
            cnt++;
            continue;
        }
        bef = rock;
    }
    if(cnt<=n) return right;
    return left;
}