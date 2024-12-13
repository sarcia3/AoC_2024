#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

int n, m;
bool is_legal (pi arg) {
    return (0 <= arg.first && arg.first < n &&
    0 <= arg.second && arg.second < m);
};

int t=0;
void dfs( pi curr, vector<vector<int>> &vis, const vector<vector<int>> &A) {
    int n = vis.size(), m=vis[0].size();

    auto [x, y] = curr;
    if(vis[x][y]) return;

    vis[x][y] = t;
    if(is_legal({x-1, y}) &&!vis[x-1][y] && A[x-1][y] == A[x][y] && !vis[x-1][y]){
        dfs({x-1, y}, vis, A);
    }
    if(is_legal({x+1, y}) &&!vis[x+1][y] && A[x+1][y] == A[x][y] && !vis[x+1][y]){
        dfs({x+1, y}, vis, A);
    }
    if(is_legal({x, y-1}) &&!vis[x][y-1] && A[x][y-1] == A[x][y] && !vis[x][y-1]){
        dfs({x, y-1}, vis, A);
    }
    if(is_legal({x, y+1}) &&!vis[x][y+1] && A[x][y+1] == A[x][y] && !vis[x][y+1]){
        dfs({x, y+1}, vis, A);
    }

    


}
signed meow() {
    cin >> n;
    vector<vector<int>> A(n);
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        vector<int> v;
        for(auto &g : s) v.push_back(g);
        A[i] = v;
    }
    m = A[0].size();

    

    vector<vector<int>> vis(n, vector<int> (m));
    for(int i =0; i <n; i++)
        for(int j=0; j<m; j++){
            if(!vis[i][j]) {
                t++;
                dfs({i, j}, vis, A);
            }
        }

    set<int> checked;
    int res=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(checked.count(vis[i][j])) continue;

            checked.insert(vis[i][j]);
            int num = vis[i][j];
            int tmp = 0;
            int cnt = 0;
            vis[i][j] = num;
            for(int x=0; x<n; x++){
                for(int y=0; y<m; y++){
                    if(vis[x][y] != num) continue;
                    cnt ++ ;
                    if(!is_legal({x-1, y}) || num != vis[x-1][y]){
                        tmp ++;
                    }
                    if(!is_legal({x+1, y}) || num != vis[x+1][y]){
                        tmp ++;
                    }
                    if(!is_legal({x, y-1}) || num != vis[x][y-1]){
                        tmp ++;
                    }
                    if(!is_legal({x, y+1}) || num != vis[x][y+1]){
                        tmp ++;
                    }
                }
            }

            res += tmp*cnt;
        }
    }

    cout << res;
}
