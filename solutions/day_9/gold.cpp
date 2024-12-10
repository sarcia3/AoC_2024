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
    map<int, int> B;
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
                B[i/2] = s[i] -'0';
            }
            it+=s[i]-'0';
        } else {
            it += s[i]-'0';
        }
    }
    for(int i = m-1; i>0; i--) {
        if(A[i-1] == A[i] || A[i] == -1) continue;
        it = 0;
        while(it < i){
            while(it<i && A[it] != -1) {
                it++;
            }
            int o = it+1;
            while(o<m && (A[o] == -1) && o-it < B[A[i]]) 
                o++;

            if(o-it == B[A[i]]){
                int y = B[A[i]];
                for(int k=0; k<y; k++){
                    swap(A[it+k], A[i+k]);
                }
                it = o;
                break;
            }
                it = o;
            if(o >= m) break;
        }
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
