#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;
typedef pair<int, int> pii;
int N;
vector<vector<int>> board;
vector<int> row;
vector<pii> col;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    board.assign(N,vector<int>(N, 0));
    row.resize(N);
    col.resize(N);
    int rs = 0, cs = 0;

    for(int i=0;i<N;i++){
        cin>>row[i];
        rs += row[i];
    }
    for(int i=0;i<N;i++){
        cin>>col[i].first;
        col[i].second = i;
        cs += col[i].first;
    }
    if(rs!=cs){
        cout<<-1;
        exit(0);
    }

    for(int i=0;i<N;i++){
        int r = row[i];
        sort(col.begin(), col.end(), greater<pii>());
        for(int j=0;j<N;j++){
            if(!r) break;
            if(col[j].first){
                r--;
                col[j].first--;
                board[i][col[j].second] = 1;
            }
        }
        if(r){
            cout<<-1;
            exit(0);
        }
    }
    cout<<1<<"\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}