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
    for(auto &s : inp) {
        for(int i=0; i<n-3; i++) {
            if(s[i] == 'X' && s[i+1] == 'M' && s[i+2] == 'A' && s[i+3] == 'S') res++;
        }
        reverse(s.begin(), s.end());
        for(int i=0; i<n-3; i++) {
            if(s[i] == 'X' && s[i+1] == 'M' && s[i+2] == 'A' && s[i+3] == 'S') res++;
        }
    }

    for(int i=0; i<inp.size()-3; i++) {
        for(int j=0; j<n; j++) {
            if(s[i][j] == 'X' && s[i+1][j] == 'M' && s[i+2][j] == 'A' && s[i+3][j] == 'S') res++;
        }
    }
    for(int i=0; i<inp.size()-3; i++) {
        for(int j=0; j<n-3; j++) {
            if(s[i][j] == 'X' && s[i+1][j+1] == 'M' && s[i+2][j+2] == 'A' && s[i+3][j+3] == 'S') res++;
        }
    }

    for(int i=0; i<inp.size()-3; i++) {
        for(int j=3; j<n; j++) {
            if(s[i][j] == 'X' && s[i+1][j-1] == 'M' && s[i+2][j-2] == 'A' && s[i+3][j-3] == 'S') res++;
        }
    }

    reverse(inp.begin(), inp.end());

    for(int i=0; i<inp.size()-3; i++) {
        for(int j=0; j<n; j++) {
            if(s[i][j] == 'X' && s[i+1][j] == 'M' && s[i+2][j] == 'A' && s[i+3][j] == 'S') res++;
        }
    }
    for(int i=0; i<inp.size()-3; i++) {
        for(int j=0; j<n-3; j++) {
            if(s[i][j] == 'X' && s[i+1][j+1] == 'M' && s[i+2][j+2] == 'A' && s[i+3][j+3] == 'S') res++;
        }
    }

    for(int i=0; i<inp.size()-3; i++) {
        for(int j=3; j<n; j++) {
            if(s[i][j] == 'X' && s[i+1][j-1] == 'M' && s[i+2][j-2] == 'A' && s[i+3][j-3] == 'S') res++;
        }
    }

}

signed meow() {
    solve(); 
}
