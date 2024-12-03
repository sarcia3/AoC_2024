#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

bool check(vector<int> prev) {  //true jak działa
    int n = prev.size();
    bool sb = false;
    int sign = 0;

    for(int j=1; j<n; j++) {
            int aaaa=abs(prev[j-1] - prev[j]);
            if(!(aaaa >= 1 && aaaa <= 3)) { sb = true; break;}
            int tmp = aaaa/(prev[j-1]-prev[j]);
            if(sign != 0 && tmp != sign){
                sb = true;
                break;
            }
            sign = tmp;
        }

    return !sb;
}
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

        int sign = 0;
        int n = prev.size();

        bool sb = false;
        for(int i=0; i<n; i++){
            vector<int> tmp;
            for(int j=0; j<n; j++){
                if(j != i) tmp.push_back(prev[j]);
            }

            sb |= check(tmp);
        }

        if(sb == 0) 
            safe--;
    }


}

signed meow() {
	solve(); 
}