#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>
#define a4 array<long long, 4>

#define meow main

using namespace std;

signed meow() {
    set<pair<string, string>> S;
    map<string, vector<string>> M;
    while(true){
        string s; cin >> s;
        if(s == "-1") 
            break;
        string s1 = s.substr(0, 2);
        string s2 = s.substr(3, 2);
        M[s1].push_back(s2);
        M[s2].push_back(s1);
        S.insert({s1, s2});
        S.insert({s2, s1});
    }

    int res=0;

    set<array< string, 3>> M2;
    for(auto i = M.begin(); i != M.end(); i++){
        auto v1 = i -> first;
        auto V = i -> second;
        sort(V.begin(), V.end());
        function<void(vector<int>)> calc = [&](vector<int> arg) {
            int n = arg.size();
            if(n==12){
                cout << v1;
                for(auto a : arg)
                    cout <<"," << V[a];

                cout << '\n';
            }

            int tmp;
            if(arg.size() == 0) tmp = -1;
            else tmp = arg.back();
            for(int j=tmp+1; j<V.size(); j++){
                bool ttt =true;
                for(auto guy : arg){
                    if(!S.count({V[guy], V[j]})) {
                        ttt = false; break;
                    }
                }

                if(ttt){
                    arg.push_back(j);
                    calc(arg);
                    arg.pop_back();
                }
            }
        };
        calc({});
    }
    


    cout << res+1;
}