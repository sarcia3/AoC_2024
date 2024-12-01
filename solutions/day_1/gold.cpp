#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

void solve() {
    int n = 1000;
    cin >> n;
    vector<int> left(n);
    map<int, int> righ;
    for(int i=0; i<n; i++) {
        cin >> left[i];
        int x; cin >> x;
        (righ[x])++;
    }

    int res = 0;
    for(int i=0; i<n; i++) res += left[i] * righ[left[i]];

    cout << res;
}

signed meow() {

	solve(); 

	return 0;
}