#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

const int n = 71;
signed meow() {
    vector<vector<int>> G(71, vector<int> (71));
    int tmp = 2974;
    while(tmp--){
        string s; cin >> s;
        int num=0;
        int i;
        for(i=0; s[i] != ','; i++){
            num*=10;
            num+=s[i]-'0';
        }
        int num2=0;
        i++;
        for(; i <s.size(); i++){
            num2*=10;
            num2+=s[i]-'0';
        }
        G[num2][num] = true;
    }
    tmp = 3450-2974;
        string s;
    while(tmp--){
        cin >> s;
    }

    queue<pair<pi, int>> Q;
    vector<vector<bool>> vis(n, vector<bool> (n));

    auto is_legal = [&](pi arg){
        return (arg.first>=0 && arg.first < 71 && 
        arg.second>=0 && arg.second < 71 &&
        !G[arg.first][arg.second] && !vis[arg.first][arg.second]);
    };

    Q.push({{0, 0}, 0});
    vector<vector<int>> dist(71, vector<int> (71, INT_MAX));

    while(Q.size()){
        auto [p, d] = Q.front();
        auto [x, y] = p;
        Q.pop();
        if(dist[x][y] <= d) continue;
        dist[x][y] = d;
        vis[x][y] = true;
        if(x==n-1&& y==n-1) break ;
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

    cout << dist[n-1][n-1];
}
