#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

void print(vector<vector<char>> G, pi pos){
    G[pos.first][pos.second] = '@';
    for(auto g : G){
        for(auto gg : g) cerr << gg;
        cerr << '\n';
    }
}
void simulate(pi &pos, pi dir, vector<vector<char>> &G){
    auto [px, py] = pos;
    auto [dx, dy] = dir;
    queue<pi> to_check; to_check.push(pos);
    set<pi> checked;
    set<pi> direct;
    while(to_check.size()) {
        auto [Cx, Cy] = to_check.front();
        to_check.pop();
        if(checked.count({Cx, Cy})) continue;
        checked.insert({Cx, Cy});
        if(dir.first && G[Cx][Cy] == ']' && !checked.count({Cx, Cy-1})) to_check.push({Cx, Cy-1});
        if(dir.first && G[Cx][Cy] == '[' && !checked.count({Cx, Cy+1})) to_check.push({Cx, Cy+1});
        Cx += dx;
        Cy += dy;
        if(G[Cx][Cy] == '#') return;

        if(G[Cx][Cy] == '[' || G[Cx][Cy] == ']') {
            to_check.push({Cx, Cy});
            direct.insert({Cx, Cy});
        }
    }
    vector<vector<char>> _G = G;
    for(auto [x, y] : checked){
        _G[x+dx][y+dy] = G[x][y];
        if(direct.count({x, y}) == 0) _G[x][y] = '.';
    }

    _G[px+dx][py+dy] = '.'; 
    pos = {px + dx, py + dy};
    G = _G;
}

signed meow() {
    int n, m; cin >> n >> m;
    vector<vector<char>> G(n, vector<char> (2*m));
    pi start;
    for(int j=0; j<n; j++){
        auto &g = G[j];
        for(int i=0; i<m; i++){
            char x; cin >> x;
            if(x == '@') {start = {j, 2*i}; g[2*i]=g[2*i+1] = '.';}
            else {
                if(x == '#') g[2*i] = g[2*i + 1] = '#';
                if(x== 'O') {
                    g[2*i] = '['; g[2*i+1]=']';
                    }
                if(x=='.') g[2*i]=g[2*i+1]='.';
            }
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
        //print(G, start);;
    }
}
    for(int i=0; i<n; i++){
        for(int j=0; j<2*m; j++){
            if(G[i][j] == '[') 
                res += (100*i)+j;
        }
    }

    cout << res-1;
}
