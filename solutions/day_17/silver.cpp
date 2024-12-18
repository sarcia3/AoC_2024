#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>
#define a4 array<long long, 4>
#define a5 array<long long, 5>

#define meow main

using namespace std;
int A, B, C;

int combo(int i){
    if(i<=3) return i;
    if(i==4) return A;
    if(i==5) return B;
    if(i==6) return C;
}

signed meow() {
    string s; cin >> s;
    cin >> s;
    cin >> A;
    cin >> s; cin >> s;
    cin >> B;
    cin >> s; cin >> s;
    cin >> C;

    vector<int> X; 
    int k; cin >> k;
    while(k--){
        int a; cin >> a;
        
        X.push_back(a);
    }
    k=X.size();
    
    int ip = 0;
    while(ip < X.size()-1){
        int inst = X[ip]; int val = X[ip+1];
        if(inst == 0){
            A = A/(1<<combo(val));
        }

        if(inst == 1){
            B = B^val;
        }

        if(inst == 2){
            B = combo(val)%8;
        }

        if(inst == 3){
            if(A==0) {ip+=2; continue;};

            ip = val;
            continue;
        }

        if(inst == 4){
            B = B^C;
        }

        if(inst == 5){
            cout << combo(val)%8 <<',';
        }

        if(inst == 6){
            B=A/(1<<combo(val));
        }

        if(inst == 7){
            C=A/(1<<combo(val));
        }

        ip+=2;
    }
}
