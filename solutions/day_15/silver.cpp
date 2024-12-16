#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

void simulate(pi &pos, pi dir, vector<vector<int>> &G){
    auto [px, py] = pos;
    auto [dx, dy] = dir;
    do{
        px +=dx;
        py+=dy;
    }while(G[px][py] != 0 && G[px][py] != 2);

    if(G[px][py]==2 || px < 0 || px >= G.size() || py<0 || py>=G[0].size()) return;

    auto &[Px, Py] = pos;
    Px += dx;
    Py += dy;
    G[px][py] = G[Px][Py];
    G[Px][Py] = 0;
}

signed meow() {
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n, vector<int> (m));
    pi start;
    for(int j=0; j<n; j++){
        auto &g = G[j];
        for(int i=0; i<m; i++){
            char x; cin >> x;
            if(x=='#') g[i] = 2;
            if(x=='O') g[i] = 1;
            if(x=='.') g[i] = 0;
            if(x=='@') start = {j, i};
        }
    }

int res=1;
int t; cin >> t;
while(t--) {
    string s; cin >> s;
    for(auto x : s){
        if(x == '<') simulate(start, {0, -1}, G);
        if(x == '>') simulate(start, {0, 1}, G);
        if(x == '^') simulate(start, {-1, 0}, G);
        if(x == 'v') simulate(start, {1, 0}, G);
    }
}
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(G[i][j] == 1) 
                res += (100*i)+j;
        }
    }

    cout << res-1;
}
