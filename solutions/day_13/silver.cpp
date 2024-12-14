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
    int y; cin >> y;
    return {num, y};
}
int solve(){
    pi A = inp(); auto [af, as] = A;
    pi B = inp(); auto [bf, bs] = B;
    pi C = _inp(); auto[cf, cs] = C;
    int res=INT_MAX;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++)
            if(af * i + bf*j == cf && as * i + bs*j == cs) res=min(res, 3*i+j) ;
    }

if(res==INT_MAX)
    return 0;
    else return res;
}

signed meow() {
    int res=0; int n; cin >> n;
    while(n--){
        res+=solve();
    }
    cout << res;
}
