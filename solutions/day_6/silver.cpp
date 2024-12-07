#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

signed meow() {
    int n, m; cin >> n >> m;
    vector<vector<int>> A(n, vector<int> (m));
    a3 start;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            char x; cin >> x;
            A[i][j] = (x=='#');
            if(x == '^') start = {i, j, 0};
        }
    }

    set<a3> vis;
    set<pi> res;

    auto &curr = start;
    while(true) {
        if(vis.count(start)) break;
        vis.insert(start);
        auto &[i, j, dir] = curr;
        res.insert({i, j});
        if(dir == 0) {
            if(i == 0) break;
            if(A[i-1][j]) dir++;
            else i--;
        } else if(dir==1) {
            if(j==m-1) break;
            if(A[i][j+1]) dir++;
            else j++;
        } else if(dir == 2) {
            if(i==n-1) break;
            if(A[i+1][j]) dir++;
            else i++;
        } else {
            if(j==0) break;
            if(A[i][j-1]) dir=0;
            else j--;
        }
    }

    cout << res.size() << '\n';
}

