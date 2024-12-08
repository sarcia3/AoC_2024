#include "bits/stdc++.h"
#define int __int128
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

bool old_solve(int goal, int val, vector<int> A, int i) {
    i++;
    if(i == A.size() )
        return val == goal;
    
    return old_solve(goal, val + A[i], A, i) || old_solve(goal, val * A[i], A, i);
}

bool solve(int goal, int val, const vector<int> &A, int i) {
    i++;
    if(i == A.size()) {
        if(val == goal)
            return val == goal;
            else return 0;
    }
    
    bool tmp = solve(goal, val + A[i], A, i) || solve(goal, val * A[i], A, i);
    if(tmp) return tmp;
    if(i==0) return tmp;
    int num = 1;
    int _a = A[i];

    while(_a) {
        num*=10;
        _a/=10;
    }
    assert(num < 10000000);
    assert(num > A[i]);
    assert(A[i]*10 >= num);
    return tmp || solve(goal, num * val + A[i], A, i);
}

signed meow() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n; cin >> n;
    vector<string> tt;
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
        assert(num!=0);
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

        if(solve(num, A[0], A, 0)) { 
            res+=num;
        }
    }
    cout << (unsigned long long) res << '\n';
}

