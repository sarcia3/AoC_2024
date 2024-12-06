#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

void solve() {
    int m = 1176;
    //int m = 21;
    vector<set<int>> ord(100);
    while(m--) {
        char a, b, pipe, c, d; cin >> a >> b >> pipe >> c >> d;
        a-='0';
        b-='0';
        c-='0';
        d-='0';
        int num1 = a*10 + b;
        int num2 = c*10 + d;
        ord[num2].insert(num1);
    }

    m = 204;
    //m=6;
    int rs = 0;
    while(m--) {
        string s; cin >> s;
        vector<int> A;
        for(int i=0; i<s.size(); i+=3)
            A.push_back(10*(s[i] - '0') + s[i+1] - '0');

        int n = A.size();

        bool res = true;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(ord[A[i]].count(A[j]) > 0) res = false;
            }
        }

        if(res) rs+=(A[n/2]);
    }

    cout << rs <<'\n';
}

signed meow() {
    solve(); 
}

