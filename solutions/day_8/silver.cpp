#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

signed meow() {
    vector<string> M;
    int n; cin >> n;
        string s;
        getline(cin, s);
    while(n--) {
        getline(cin, s);
        M.push_back(s);
    }
    n = M.size();
    int m = M[0].size();


    set<pair<int, int>> res;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            for(int i2=0; i2<n; i2++) {
                for(int j2=0; j2<m; j2++) {
                    if((i == i2 && j == j2) || M[i][j] != M[i2][j2] || M[i][j] == '.' || M[i2][j2] == '.') continue;
                    
                    int veci = i-i2;
                    int vecj = j-j2;
                    int vali = i + veci;
                    int valj = j + vecj;
                    if(vali >= 0 && vali < n && valj >=0 && valj < m) {
                        res.insert({vali, valj});
                    }
                }
            }
        }
    }
    cout << res.size();
}

