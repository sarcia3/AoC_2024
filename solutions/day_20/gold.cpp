#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

int n, m;

void print(vector<vector<char>> G){
    for(auto &GG: G){
        for(auto &g : GG) cerr << g;
        cerr << '\n';
    }
}
vector<vector<int>> dist(const vector<vector<char>> &G, pi start){
    queue<pair<pi, int>> Q;
    vector<vector<bool>> vis(n, vector<bool> (m));

    auto is_legal = [&](pi arg){
        return (arg.first>=0 && arg.first < n && 
        arg.second>=0 && arg.second < m &&
        !(G[arg.first][arg.second]=='#') && !vis[arg.first][arg.second]);
    };

    Q.push({start, 0});
    vector<vector<int>> dist(n, vector<int> (m, INT_MAX));

    while(Q.size()){
        auto [p, d] = Q.front();
        auto [x, y] = p;
        Q.pop();
        if(dist[x][y] <= d) continue;
        dist[x][y] = d;
        vis[x][y] = true;
        if(is_legal({x+1, y})){
            Q.push({{x+1, y},d+1});
           // dist[x+1][y] = d+1;
        }
        if(is_legal({x, y+1})){
            Q.push({{x, y+1},d+1});
           // dist[x][y+1] = d+1;
        }
        if(is_legal({x-1, y})){
            Q.push({{x-1, y},d+1});
          //  dist[x-1][y] = d+1;
        }
        if(is_legal({x, y-1})){
            Q.push({{x, y-1},d+1});
          //  dist[x][y-1] = d+1;
        }
    }

    return dist;
}
signed meow() {
    cin >> n >> m;
    vector<vector<char>> G(n, vector<char> (m));
    pi start, end;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> G[i][j];
            if(G[i][j] == 'S') start = {i, j};
            if(G[i][j] == 'E') end = {i, j};
        }

    int res=0;

    auto is_legal = [&](pi arg){
        return (arg.first>=0 && arg.first < n && 
        arg.second>=0 && arg.second < m &&
        !(G[arg.first][arg.second]=='#'));
    };

    vector<vector<vector<vector<int>>>> dists(n, vector<vector<vector<int>>> (n, vector<vector<int>> (n, vector<int>(n))));
    for(int i=0; i<n; i++){
        cout << i << '\n';
        for(int j=0; j<n; j++){
            if(G[i][j] =='#') continue; 
            dists[i][j] = dist(G,{i, j});
        }
    }
    int base = dists[start.first][start.second][end.first][end.second];
    for(int i=0; i<n; i++){
        cout << i << '\n';
        for(int j=0; j<m-1; j++){
            if(G[i][j] == '#') continue;
            if(base-dists[start.first][start.second][i][j] < 100) continue;
            for(int _i = -20; _i<=20; _i++){
                for(int _j=-20; _j<=20; _j++){
                    if(abs(_i) + abs(_j) <=20 && is_legal({i, j}) && is_legal({i+_i, j+_j})){
                        int tmp = dists[start.first][start.second][i][j] + dists[end.first][end.second][i+_i][j+_j] + abs(_i) + abs(_j);
                        if(base-tmp >= 100)
                            res++;
                    }
                }
            }
        }
    }
    cout << '\n' <<res;
}