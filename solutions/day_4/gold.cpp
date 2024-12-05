#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

void solve() {
    vector<string> inp (140);
    for(auto &s: inp) cin >> s;
    
    int res=0;
    auto &s = inp;
    int n = s[0].size();
    for(int i=1; i<inp.size()-1; i++){
        for(int j=1; j<n-1; j++) {
            if(s[i][j] == 'A'){
                if((s[i-1][j-1] == 'M' && s[i+1][j+1] == 'S') ||(s[i-1][j-1] == 'S' && s[i+1][j+1] == 'M')){
                    if((s[i+1][j-1] == 'M' && s[i-1][j+1] == 'S') ||(s[i+1][j-1] == 'S' && s[i-1][j+1] == 'M')){
                        res++;
                    }
                }
            }
        }
    }
}

signed meow() {
    solve(); 
}
