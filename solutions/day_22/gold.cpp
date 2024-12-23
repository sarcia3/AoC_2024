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
        int tmp;
        
        tmp = sim(x);
        int _0 = (x%10) - (tmp)%10;
        x = tmp;
        
        tmp = sim(x);
        int _1 = (x%10) - (tmp)%10;
        x = tmp;
        
        tmp = sim(x);
        int _2 = (x%10) - (tmp)%10;
        x = tmp;
        
        tmp = sim(x);
        int _3 = (x%10) - (tmp)%10;
        x = tmp;

        V.back()[{_0, _1, _2, _3}] = x%10;
        for(int i=4; i<2000; i++)  {
            _0 = _1;
            _1 = _2;
            _2 = _3;
            tmp = sim(x);
            _3 = (x%10) - (tmp)%10;
            x = tmp;
            if(_0 == 9 && _1 == -9 && _2 == 1 && _3 == 0) 
                cerr << "\n";
            if(!V.back().count({_0, _1, _2, _3})) {
                V.back()[{_0, _1, _2, _3}] = x%10;
                big[{_0, _1, _2, _3}] += x%10;
            }
        }
    }

    for(int i1 = -9; i1 <= 9; i1++)
    for(int i2 = -9; i2 <= 9; i2++)
    for(int i3 = -9; i3 <= 9; i3++)
    for(int i4 = -9; i4 <= 9; i4++){
        cerr << i1 << '\n';
        if(big[{i1, i2, i3, i4}] == 24) 
            cerr << i1 << ' ' << i2 << ' '<< i3 << ' ' << i4 <<'\n';
        if(big.count({i1, i2, i3, i4})) 
            res = max(res, big[{i1, i2, i3, i4}]);
    }
    cout << res;
}