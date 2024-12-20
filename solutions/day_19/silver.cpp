//reconstruction of the solution
#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

signed meow() {
    int k; cin >> k;
    set<string> aval;
    int max_size=0;
    for(int i=0; i<k; i++) { 
        string s; cin >> s; aval.insert(s); max_size = max(max_size, (int)s.size());
        }

    int res=0;
    while(true) {
        string s; cin >> s; int n = s.size();
        if(s=="break") break;
        for(int i=0; i<n; i++){
            for(int j=0; j<max_size+1; j++){
                if(aval.count(s.substr(0, i-j+1)) && aval.count(s.substr(i-j+ 1, j)))
                    aval.insert(s.substr(0,i+1));
            }
        }
        res+=aval.count(s);
    }

    cout << res << '\n';
}
