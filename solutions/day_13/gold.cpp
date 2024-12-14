#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

pi inp(){
    string s;
    cin >> s;
    cin >> s;
    char x;
    cin >> x;
    cin >> x;
    char y;
    cin >> x >> y;
    pi A;
    A.first = (x-'0')*10 + (y-'0');
    cin >> x;
    cin >> x;
    cin >> x;

    cin >> x >> y;
    A.second = (x-'0')*10+(y-'0');

    return A;
}

pi _inp(){
    string s; cin >> s;
    char x;
    cin >>x;
    cin >> x;
    int num=0;
    cin >> x;
    while(x != ','){
        num*=10;
        num += x-'0';
        cin >> x;
    }
    cin >> x;
    cin >> x;
    long long y; cin >> y;
    return {num, y};
}

int solve(){
    pi A = inp(); auto &[af, as] = A;
    pi B = inp(); auto &[bf, bs] = B;
    pi C = _inp(); auto &[cf, cs] = C;
    cf+=10000000000000;
    cs+=10000000000000;
    
    int mul = 3;
    if(af / bf == as /bs && af % bf == 0 && as % bs ==0 ){
        mul = 1;
        swap(A, B);
    }

    if(bf / af == bs / as && bf % af == 0 && bs % as == 0){
        if(cf/af == cs/as && cf % af == 0 && cs % as == 0) return mul * cf/af;
        else return 0; 
    }

    //af*x + bf*y = cf
    //as*x + bs*y = cs

    int x= (cf*bs - bf*cs)/(af*bs - bf*as);
    int y= (cs*af - cf*as)/(af*bs - bf*as);

    if(x*af + y *bf == cf && as*x + bs*y == cs && x>=0 && y>=0) 
        return x*3+y;

    return 0;

}

signed meow() {
    long long res=0; long long n; cin >> n;
    while(n--){
        res+=solve();
    }
    cout << res;
}
