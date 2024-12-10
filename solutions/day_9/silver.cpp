#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

void solve() {
    string s; cin >> s;
    int m=0;
    for(auto &_s : s) m += _s-'0';
    int n = s.size();
    vector<int> A (m, -1);
    int it = 0;
    int sub=0;
    for(int i=0; i<n; i++) {
        if(i==4093){
            cerr<<"test\n";
        }
        if(i%2 == 0){
            if(s[i] == '0') {
                sub++; continue;
            }
            for(int k=0; k<s[i]-'0'; k++){
                A[it+k] = i/2 - sub;
            }
            it+=s[i]-'0';
        } else {
            it += s[i]-'0';
        }
    }

    for(int i = m-1; i>=0; i--) {
        cerr << i << '\n';
        it=0;
        while(it<i && A[it] != -1) {
            it++;
        }
        if(it != i) swap(A[i], A[it]);
    }

    int res = 0;
    for(int i=0; i<m; i++) {
        if(A[i] != -1)
            res += A[i] * i;
    }

    cout << res;


}

signed meow() {

    solve(); 

    return 0;
}
