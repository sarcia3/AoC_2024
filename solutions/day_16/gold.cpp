#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>
#define a4 array<long long, 4>
#define a5 array<long long, 5>

#define meow main

using namespace std;

 
void nextdir(pi &dir){
    auto &[l, r] = dir;
    if(l == 0 && r == -1) dir  = {0, 1};
    else if(l == 0 && r == 1) dir  = {-1, 0};
    else if(l == -1 && r == 0) dir  = {1, 0};
    else dir  = {0, -1};
}

int numdir(pi dir){
    auto &[l, r] = dir;
    if(l == 0 && r == -1) return 0;
    else if(l == 0 && r == 1) return 1;
    else if(l == -1 && r == 0)return 2;
    else return 3;
}

pi dirnum(int i){
    if(i==0) return {0, -1};
    if(i==1) return {0,1 };
    if(i==2) return {-1, 0};
    if(i==3) return {1, 0};
}

signed meow() {
    int n, m; cin >> n >> m;
    vector<vector<char>> G(n, vector<char> (m));
    pi start, end; 
    auto &[startx, starty] = start;
    auto &[endx, endy] = end;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            auto &g = G[i][j];
            cin >> g;
            if(g == 'S'){
                start = {i, j};
            }
            if(g=='E'){
                end = {i, j};
            }
        }
    }

    priority_queue<a5> Q;
    set<a4> in_q;
    map<a4, int> dist;
    int dirx = 0, diry = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            pi dir = {0, -1};
            for(int k=0; k<4; k++){
                dist[{i, j, dir.first, dir.second}] = INT_MAX;
                if(i != startx || j != starty){
                   // Q.push({-INT_MAX, i, j, dir.first, dir.second});
                    in_q.insert({i, j, dir.first, dir.second});
                }
                nextdir(dir);
            }          
        }
    }
    dist[{startx, starty, dirx, diry}] = 0;
    Q.push({0, startx, starty, dirx, diry});
    in_q.insert({startx, starty, dirx, diry});
    int res =INT_MAX;
    vector<vector<vector<set<a3>>>> prev(n, vector<vector<set<a3>>> (m, vector<set<a3>>(4)));
    while(Q.size()){
        auto [d, x, y, dirx, diry] = Q.top();
        if(x==13 && y ==13)
            cerr << "test";
        Q.pop();
        d*=-1;
        if(x== endx && y == endy) res= min(res, d);
        pi old_dir = {dirx, diry};
        pi dir = old_dir;
        for(int i=0; i<4; i++){
            if(old_dir.first == -dir.first && old_dir.second == -dir.second) { nextdir(dir); continue;}
            int tmp = d;
            if(old_dir == dir) {
                tmp++;
            } else tmp+=1001;

            if(x+dir.first<0 || x+dir.first>= n || y+dir.second< 0 || y+dir.second >= m || G[x+ dir.first][y+dir.second] == '#' ){
                nextdir(dir);
                continue;
            } else {
                if(tmp == dist[{x+dir.first, y+dir.second, dir.first, dir.second}]){
                    prev[x+dir.first][y+dir.second][numdir(dir)].insert({x, y, numdir(old_dir)});
                    dist[{x+dir.first, y+dir.second, dir.first, dir.second}] =tmp;
                    //Q.push({-tmp, x+dir.first, y+dir.second, dir.first, dir.second});
                }
                if(tmp < dist[{x+dir.first, y+dir.second, dir.first, dir.second}]){
                    dist[{x+dir.first, y+dir.second, dir.first, dir.second}] =tmp;
                    Q.push({-tmp, x+dir.first, y+dir.second, dir.first, dir.second});
                    prev[x+dir.first][y+dir.second][numdir(dir)]={{x, y, numdir(old_dir)}};
                }
                nextdir(dir);
            }
        }
    }
    
    stack<a4> tmp;
    if(dist[{endx, endy, 0, 1}] >= dist[{endx, endy, -1, 0}]) tmp.push({endx, endy, -1, 0});
    if(dist[{endx, endy, 0, 1}] <= dist[{endx, endy, -1, 0}]) tmp.push({endx, endy, 0, 1});
    set<pi> rres;
    rres.insert({endx, endy});
    while(tmp.size()){
        auto[x, y, dirx, diry] = tmp.top();
        tmp.pop();
        int h = numdir({dirx, diry});
        for(auto[_x, _y, _num] : prev[x][y][h]){
            rres.insert({_x, _y});
            tmp.push({_x, _y, dirnum(_num).first, dirnum(_num).second });
        }

    }

    cout << rres.size();
}