#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>
#define a4 array<long long, 4>
#define a5 array<long long, 5>

#define meow main

using namespace std;
int A, B, C;
vector<int> X; 

int combo(int i){
    if(i<=3) return i;
    if(i==4) return A;
    if(i==5) return B;
    if(i==6) return C;
    if(i==7) return -1;
}

int sim(int _A, int cu){
    for(int i=0; i<8; i++) {
        A = _A*8 + i;
        int ip = 0;
        while(ip < X.size()-1){
            int inst = X[ip]; int val = X[ip+1];
            if(inst == 0){
                if(combo(val) == -1) break;
                A = A/(1<<combo(val));
            }

            if(inst == 1){
                B = B^val;
            }

            if(inst == 2){
                if(combo(val) == -1) break;
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
                if(combo(val) == -1) break;
                if(combo(val)%8 == X[cu]){
                    if(cu==0) cout << _A << '\n';
                    else sim(A, cu-1);
                }
                break;
            }

            if(inst == 6){
                if(combo(val) == -1) break;
                B=A/(1<<combo(val));
            }

            if(inst == 7){
                if(combo(val) == -1) break;
                C=A/(1<<combo(val));
            }

            ip+=2;
        }
    }

    return 0;
}

signed meow() {
    int k; cin >> k;
    while(k--){
        int a; cin >> a;
        
        X.push_back(a);
    }
    k=X.size();

    vector<int> good;
    good.push_back(7);
    for(int cu = k-2; cu>=0; cu--){
        vector<int> ngood;
        for(auto g : good){
            g*=8;
            for(int i=0; i<8; i++){
                int _g = A = g+i;
                int ip = 0;
                while(ip < X.size()-1){
                    int inst = X[ip]; int val = X[ip+1];
                    if(inst == 0){
                        if(combo(val) == -1) break;
                        A = A/(1<<combo(val));
                    }

                    if(inst == 1){
                        B = B^val;
                    }

                    if(inst == 2){
                        if(combo(val) == -1) break;
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
                        if(combo(val) == -1) break;
                        if(combo(val)%8 == X[cu]){
                            ngood.push_back(_g);
                        }
                        break;
                    }

                    if(inst == 6){
                        if(combo(val) == -1) break;
                        B=A/(1<<combo(val));
                    }

                    if(inst == 7){
                        if(combo(val) == -1) break;
                        C=A/(1<<combo(val));
                    }

                    ip+=2;
                }
            }
        }

        good = ngood;
    }
    sort(good.begin(), good.end());
    cout << good[0];
}
