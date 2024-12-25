#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>
#define a4 array<long long, 4>

#define meow main

using namespace std;

signed meow() {
    set<pair<string, string>> S;
    map<string, set<string>> M;
    while(true){
        string s; cin >> s;
        if(s == "-1") break;
        string s1 = s.substr(0, 2);
        string s2 = s.substr(3, 2);
        M[s1].insert(s2);
        M[s2].insert(s1);
        S.insert({s1, s2});
        S.insert({s2, s1});
    }

    int res=0;
    for(auto i = M.begin(); i != M.end(); i++){
        auto v1 = i -> first;
        auto V = i -> second;
        int tmp=0;
        for(auto v2 : V){
            for(auto p : V)
                tmp += S.count({v1, p}) * S.count({v2, p}) *(v1[0] == 't' || v2[0] == 't' || p[0] == 't');
        }

        res += tmp;
    }

    cout << res/6;
}