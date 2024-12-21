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
int dist(const vector<vector<char>> &G, pi start, pi end){
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
        if(p == end) break ;
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

    return dist[end.first][end.second];
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
    int base = dist(G, start, end);
    for(int i=0; i<n; i++){
        cout << i << '\n';
        for(int j=0; j<m-1; j++){
            int old1= G[i][j];
            if(G[i][j] == '#'){
                G[i][j]='.';
                int dst = dist(G, start, end);
                if( base-dst >= 100) {
                    res++;
                }

                G[i][j] = old1;

            }
        }
    }
    cout << res;
    /*
    return 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m-1; j++){
            if(i== 6 && j ==5)
                cerr << "a";
            int old1= G[i][j], old2 = G[i][j+1];
            if(G[i][j] == '#' || G[i][j+1]=='#'){
                bool imp1=true, imp2=true;
                G[i][j]=G[i][j+1]='.';
                int dst = dist(G, start, end);
                if(old1 == '#'){
                    G[i][j] = '.';
                    int _dst = dist(G, start, end);
                    if(_dst == dst) imp1= false;
                    if(base-_dst >= 100) {
                        pair<pi, pi> tmp = {{i, j+1}, {-1, -1}};
                        res.insert(tmp);
                    }
                    G[i][j] = '#';
                }
                if(old2 == '#'){
                    G[i][j+1] = '.';
                    int _dst = dist(G, start, end);
                    if(_dst == dst) imp2= false;
                    if(base-_dst >= 100) {
                        pair<pi, pi> tmp = {{i, j}, {-1, -1}};
                        res.insert(tmp);
                    }
                    G[i][j] = '#';
                }
                if(imp1 && imp2 && base-dst >= 100) {
                    pair<pi, pi> tmp = {{i, j}, {i, j+1}};
                    res.insert(tmp);
                }

                G[i][j] = old1;
                G[i][j+1] = old2;

            }
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            if(i== 6 && j ==6)
                cerr << "a";
            int old1= G[i][j], old2 = G[i+1][j];
            if(G[i][j] == '#' || G[i+1][j]=='#'){
                bool imp1=true, imp2=true;
                G[i][j]=G[i+1][j]='.';
                int dst = dist(G, start, end);
                if(old1 == '#'){
                    G[i][j] = '.';
                    int _dst = dist(G, start, end);
                    if(_dst == dst) imp1= false;
                    if(base-_dst >= 100) {
                        pair<pi, pi> tmp = {{i+1, j}, {-1, -1}};
                        res.insert(tmp);
                    }
                    G[i][j] = '#';
                }
                if(old2 == '#'){
                    G[i+1][j] = '.';
                    int _dst = dist(G, start, end);
                    if(_dst == dst) imp2= false;
                    if(base-_dst >= 100) {
                        pair<pi, pi> tmp = {{i, j}, {-1, -1}};
                        res.insert(tmp);
                    }
                    G[i][j] = '#';
                }
                if(imp1 && imp2 && base-dst >= 100) {
                    pair<pi, pi> tmp = {{i+1, j}, {i, j}};
                    res.insert(tmp);
                }

                G[i][j] = old1;
                G[i+1][j] = old2;

            }
        }
    }

    cout << res.size() << '\n';
    */
}