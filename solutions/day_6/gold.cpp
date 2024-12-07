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


    int num = 0;
    for(int k=0; k<n; k++){

        cout << k << '\n';
    for(int kk=0; kk<n; kk++) {
        if(A[k][kk] == 1 || (start[0] == k && start[1] == kk)) continue;
        set<a3> vis;
        A[k][kk] = 1;
        auto curr = start;
        bool tmp = false;
        while(true) {
            if(vis.count(curr)) { tmp = true; break;}
            vis.insert(curr);
            auto &[i, j, dir] = curr;
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
        num += tmp;
        A[k][kk] = 0;
    }
    }
    cout << num << '\n';
}

