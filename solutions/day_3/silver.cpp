#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

void solve() {
    int m=1000;
    string s;
    string tmp;
    for(int i=0; i<6; i++) {
        getline(cin, tmp);
        s.push_back('X');
        s += tmp;
    }
    int n = s.size();
    int res = 0;
    for(int ind=0; ind<n-7; ind++) {
        int i = ind;
        if(s[i] == 'm' && s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '(') {
            int num1=0;
            i+=4;
            while(i<n && s[i] >= '0' && s[i] <= '9') {
                num1*=10; num1+=s[i]-'0';
                i++;
            }
            if(i<n && s[i] == ',' && num1 != 0){
                i++;
                int num2 = 0;
                while(i<n && s[i] >= '0' && s[i] <= '9') {
                    num2*=10; num2+=s[i]-'0';
                    i++;
                }

                if(i<n && s[i] == ')') {
                    res += num1*num2; 
                    continue;
                }
            }
        }
    }
    cout << res << '\n';
}

signed meow() {
	solve(); 
}
