#include <string>
#include <vector>
#include <deque>
using namespace std;
typedef deque<int> di; //덱
di left;
di right;
deque<di> middle;
void shift(){
    left.push_front(left.back());
    left.pop_back();
    
    right.push_front(right.back());
    right.pop_back();
    
    middle.push_front(move(middle.back()));
    middle.pop_back();
}

void rotate(){
    middle.front().push_front(left.front()); //[0,0] -> [0,1]
    left.pop_front();
    
    right.push_front(middle.front().back()); //[0,N-2] -> [0,N-1]
    middle.front().pop_back();
    
    middle.back().push_back(right.back()); //[N-1,N-1] -> [N-1, N-2]
    right.pop_back();
    
    left.push_back(middle.back().front()); //[N-1, 1] -> [N-1, 0]
    middle.back().pop_front();
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    int rsize = rc.size();
    int csize = rc[0].size();
    for(int i=0;i<rsize;i++){
        left.push_back(rc[i][0]);
        right.push_back(rc[i][csize-1]);
        di mid;
        for(int j=1;j<csize-1;j++){
            mid.push_back(rc[i][j]);
        }
        middle.push_back(mid);
    }
    vector<vector<int>> answer(rsize, vector<int>(csize));
    for(string &op : operations){
        if(op == "ShiftRow") shift();
        else rotate();
    }
    for(int i=0;i<rsize;i++){
        answer[i][0] = left[i];
        for(int j=1;j<csize-1;j++){
            answer[i][j] = middle[i][j-1];
        }
        answer[i][csize-1] = right[i];
    }
    return answer;
}