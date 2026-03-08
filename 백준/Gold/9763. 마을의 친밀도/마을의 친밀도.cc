#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

typedef pair<int, int> pii;
int N;
int dist(vector<int> &v1, vector<int> &v2){
	int sum = 0;
	sum += abs(v1[0] - v2[0]);
	sum += abs(v1[1] - v2[1]);
	sum += abs(v1[2] - v2[2]);
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>N;
	vector<vector<int>> vil;
	for(int i=0;i<N;i++){
		int x, y, z;
		cin>>x>>y>>z;
		vil.push_back({x, y, z});
	}
	int res = INT_MAX;
	for(int i=0;i<N;i++){
		int m1 = 3001, m2 = 3001;
		for(int j=0;j<N;j++){
			if(i==j) continue;
			m1 = dist(vil[i], vil[j]);
			if(m1>=res) continue;
			for(int k=j+1;k<N;k++){
				if(k==j || k==i) continue;
				m2 = dist(vil[i], vil[k]);
				if(m2>=res) continue;
				res = min(res, m1+m2);
			}
		}
	}
	cout<<res;
}	