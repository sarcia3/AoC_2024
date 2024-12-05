//reconstruction
#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

void solve() {
    int m=1000;
    int safe = m;

    for(int i=0; i<m; i++){
        string s; 
        getline(cin, s, '\n');
        vector<int> prev;
        int curr = 0;
        for(auto tmp : s) {
            if(tmp != ' ' && tmp != '\n') {
                curr*=10;
                curr += tmp -'0';
            } else {
                prev.push_back(curr);
                curr = 0;
            }
            if(tmp == '\n') break;

        }
        prev.push_back(curr);
        int n = prev.size();
        int sign = 0;

        for(int j=1; j<n; j++) {
            int aaaa=abs(prev[j-1] - prev[j]);
            if(!(aaaa >= 1 && aaaa <= 3)) { safe--; break;}
            int tmp = aaaa/(prev[j-1]-prev[j]);
            if(sign != 0 && tmp != sign){
                safe--;
                break;
            }
            sign = tmp;
        }
    }
}

signed meow() {
	solve(); 
}