#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>
#define a4 array<long long, 4>

#define meow main

using namespace std;

signed meow() {
    map<string, int> vals;
    
    while(true){
        string s; cin >> s;
        if(s == "-1") break;
        int v; cin >> v;
        vals[s] = v;
    }

    map<string, array<string, 3>> M;
    while(true){
        string a; cin >> a;
        if(a== "-1") break;
        string b; cin >> b;
        string c; cin >> c;
        string d; cin >> d;
        M[d] = {a, b, c};
    }
    function<int(string)> dfs = [&](string v){
        if(vals.count(v)) return vals[v];
        else {
            auto [a, b, c] = M[v];
            if(b == "AND") return (vals[v] = dfs(a) & dfs(c));
            if(b == "OR") return (vals[v] = dfs(a) | dfs(c));
            if(b == "XOR") return (vals[v] = dfs(a) ^ dfs(c));
        }
        return (int)0;
    };

    unsigned long long res = 0;
    for(int i=0; i<99; i++){
        string tmp;
        tmp = "z";
        if(i<10) tmp.push_back('0');
        else tmp.push_back(i/10 + '0');

        tmp.push_back(i%10 + '0');

        res += ((unsigned long long)1 << i) * dfs(tmp);
    }

    cout << res << '\n';
}