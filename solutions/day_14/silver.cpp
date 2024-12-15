#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;
int n, m; 

void simulate(pi &pos, const pi & move){
    auto &[x, y] = pos;
    auto [v1, v2] =move;
    int t=100;
    while(t--){
        x+=v1;
        y+=v2;
        if(x<0) x+=n;
        if(y<0) y+=m;
        if(x>=n) x-= n;
        if(y>=m) y-=m;
    }
}

pi nums(string s){
    int i=2;
    bool mn = false;
    if(s[i] == '-') {mn=true; i++;}

    int RES=0;
    while(i<s.size() && s[i]>= '0' && s[i] <='9') {
        RES*=10;
        RES+=s[i]-'0';
        i++;
    }
    i++;

    bool MN = false;
    if(s[i] == '-'){ MN=true; i++;}
    int res=0;
    while(i<s.size() && s[i]>= '0' && s[i] <='9') {
        res*=10;
        res+=s[i]-'0';
        i++;
    }

    if(mn) RES *= -1;
    if(MN) res *= -1;
    return {RES, res};
}
signed meow() {
    cin >> n >> m;

    int k; cin >> k;
    vector<pi> pos;
    vector<pi> vecs;
   for(int i=0; i<k; i++){
        string s; cin >> s;
        pos.push_back(nums(s));
        swap(pos.back().first, pos.back().second);
        cin >> s;
        vecs.push_back(nums(s));
        swap(vecs.back().first, vecs.back().second);
    }

    for(int i=0; i<k; i++){
        simulate(pos[i], vecs[i]);
    }

    int lu=0, ru=0, ld=0, rd=0;
    for(auto [y, x] : pos) {
        if(x<m/2 && y<n/2) lu++;
        if(x>=m/2+1 && y<n/2) ru++;
        if(x<m/2 && y>= n/2+1) ld++;
        if(x>= m/2+1 && y>= n/2+1) rd++;

    }

    cout << lu*ru*ld*rd;
}
