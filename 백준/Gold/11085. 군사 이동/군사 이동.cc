#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(const vector<int> a, const vector<int> b) {
    return a[2] > b[2];
}
vector<int> parent;
int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}
void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p, w, c, v;
    cin>>p>>w>>c>>v;

    vector<vector<int>> rodes(w, vector<int>(3));
    for (int i = 0; i < w; ++i) {
        cin >> rodes[i][0] >> rodes[i][1] >> rodes[i][2];
    }
    sort(rodes.begin(), rodes.end(), compare);

    parent.resize(p);
    for (int i = 0; i < p; ++i) {
        parent[i] = i;
    }
    for (auto rode : rodes) {
        int a = find(rode[0]);
        int b = find(rode[1]);
        if(a<b) parent[b] = a;
        else parent[a] = b;
        if (find(c) == find(v)) {
            cout << rode[2] << "\n";
            break;
        }
    }

    return 0;
}