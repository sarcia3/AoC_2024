#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>
#define a4 array<long long, 4>

#define meow main
int MOD = 16777216;
using namespace std;

int sim(int k){
    k = ((k*64)^k)%MOD;
    k = ((k/32)^k)%MOD;
    k = ((k*2048)^k)%MOD;
    return k;
}
signed meow() {
    int res = 0;
    vector<map<a4, int>> V;
    map<a4, int> big;
    while(true) {
        int x; cin >> x;
        if(x==-1) break;
        V.push_back({});
        
        vector<int> tmp(2001);
        tmp[0] = x;

        for(int i=0; i<2000; i++) 
            tmp[i+1] = sim(tmp[i]);

        for(int i=1; i<2001-3; i++){
            a4 _tmp = {
                tmp[i]%10-tmp[i-1]%10,
                tmp[i+1]%10-tmp[i]%10,
                tmp[i+2]%10-tmp[i+1]%10,
                tmp[i+3]%10-tmp[i+2]%10
            };

            if(!V.back().count(_tmp)) {
                V.back()[_tmp] = x%10;
                big[_tmp] += tmp[i+3]%10;
            }
        }
    }

    int mx=0;
    for(auto [a, b] : big) mx = max(mx, b);
    cout << mx;
}