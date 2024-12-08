//reconstruction
#include "bits/stdc++.h"
#define int __int128
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

bool solve(int goal, int val, const vector<int> &A, int i) {
    i++;
    if(i == A.size()) 
        return val == goal;
    return solve(goal, val + A[i], A, i) || solve(goal, val * A[i], A, i);
}

signed meow() {
    long long n; cin >> n;
    int res = 0;
        string s;
        getline(cin, s);
    while(n--) {
        getline(cin, s);
        int i=0;
        int num = 0;
        while(i< s.size() && s[i] != ':') {
            num *= 10;
            num += s[i]-'0';
            i++;
        }

        i+=2;

        vector<int> A;
        for(; i < s.size(); i++) {
            int k = 0;
            while(i<s.size() && s[i] != ' ') {
                k*=10;
                k+=s[i]-'0';
                i++;
            }

            A.push_back(k);
        }

        res+=num*solve(num, 0, A, -1);
    }
    cout << (long long) res << '\n';
}

