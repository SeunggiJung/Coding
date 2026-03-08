#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

typedef pair<int, int> pii;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};
int N, M;
vector<vector<char>> board;
vector<vector<bool>> visited;
vector<vector<bool>> res;
pii s, e;
int mini = INT_MAX;
void dfs(int depth, pii cur){
	if(depth>=mini) return;
	if(cur==e){
		mini = depth;
		res = visited;
		return;
	}
	for(int i=0;i<4;i++){
		int nr = cur.first + dr[i];
		int nc = cur.second + dc[i];
		if(nr<0||nc<0||nr>=N||nc>=M) continue;
		if(visited[nr][nc]) continue;
		if(board[nr][nc]=='+') continue;
		visited[nr][nc] = true;
		dfs(depth+1, {nr, nc});
		visited[nr][nc] = false;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>N>>M;
	board.assign(N, vector<char>(M));
	visited.assign(N, vector<bool>(M, false));
	vector<pii> se;
	for(int i=0;i<N;i++){
		string in;
		cin>>in;
		for(int j=0;j<M;j++){
			board[i][j] = in[j];
			if(board[i][j]=='.' &&(!i || !j || i==N-1 || j==M-1)) se.push_back({i,j});
		}
	}
	s = se[0], e = se[1];
	visited[s.first][s.second] = true;
	dfs(0, s);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(board[i][j]=='+') cout<<'+';
			else{
				if(!res[i][j]) cout<<"@";
				else cout<<".";
			}
		}
		cout<<"\n";
	}
}	