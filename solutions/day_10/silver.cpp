#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

void dfs(pi v, pi parent, vector<vector<bool>> &vis, const vector<vector<vector<pi>>> &G) {
        auto [_i, _j] = v;
        vis[_i][_j] = true;

        for(auto [i, j] : G[_i][_j]){
            pi tmp = {i, j};
            if(tmp != parent && !vis[i][j])
                dfs(tmp, v, vis, G);
        }
}

void nextdir(pi &dir){
    auto &[l, r] = dir;
    if(l == 0 && r == -1) dir  = {0, 1};
    else if(l == 0 && r == 1) dir  = {-1, 0};
    else if(l == -1 && r == 0) dir  = {1, 0};
    else dir  = {0, -1};
}

signed meow() {
    int n; cin >> n;
    int m;
    //vector<vector<vector<vector<int>>>> G(n, vector<vector<vector<int>>> (m, vector<vector<int>>(n, vector<int>(m)));

    vector<vector<int>> map(n);
    for(int i=0; i<n; i++){
        string s; cin >> s;
        vector<int> tmp;
        for(auto k : s) {if(k=='.') tmp.push_back(INT_MAX); else tmp.push_back(k-'0');}
        map[i]=tmp;
        m = s.size();
    }
    vector<vector<vector<pi>>> G(n, vector<vector<pi>>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            pi tmp = {0, 1};
            for(int k=0; k<4; k++) {
                auto [i2, j2] = tmp;
                i2 += i;
                j2 += j;
                if((0 <= i2 && i2 < n && 0 <= j2 && j2 < m)) 
                    if(i != i2 || j2 != j)
                        if(/*map[i][j] == map[i2][j2] ||*/ map[i][j]+1 == map[i2][j2])
                            G[i][j].push_back({i2, j2});
                nextdir(tmp);
            }
        }


    int res=0;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            if(map[i][j] != 0) continue;
            vector<vector<bool>> vis(n, vector<bool> (m));
            dfs({i, j}, {-1, -1}, vis, G);
            for(int i2=0; i2<n; i2++)
                for(int j2=0; j2<m; j2++) 
                    if(vis[i2][j2] && (map[i2][j2] == 9))
                        res ++;
        }

    cout << res << '\n';
}
