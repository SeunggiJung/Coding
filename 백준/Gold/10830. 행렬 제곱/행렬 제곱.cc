#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef pair<int,int> pii;
typedef vector<vector<int>> mat;
mat origin;
long long N, B;
mat mult(mat X, mat Y){
    mat tmp(N, vector<int>(N, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                tmp[i][j] += (X[i][k] * Y[k][j]);
            }
            tmp[i][j] %= 1000;
        }
    }
    return tmp;
}
mat dc(long long depth){
    if(depth==1){
        return origin;
    }
    mat half = dc(depth/2);
    mat res = mult(half, half);
    if(depth%2 != 0) res = mult(res, origin);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>B;
    origin.resize(N, vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>origin[i][j];
        }
    }
    mat res = dc(B);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<res[i][j]%1000<<" ";
        }
        cout<<"\n";
    }
}