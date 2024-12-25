#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>
#define a4 array<long long, 4>

#define meow main

using namespace std;

signed meow() {
    map<vector<int>, int> keys;
    map<vector<int>, int> locks; 

    while(true){
        vector<string> strings (7);
        for(auto &s : strings){ 
            cin >> s; 
            if(s == "-1") 
                break;
        }
        if(strings.back().size() == 0) break;
        vector<int> vals(5);
        for(int i=0; i<5; i++)
            for(int j=1; j<6; j++)
                vals[i] += strings[j][i] == '#';

        if(strings[0][0] ==  '.') keys[vals]++;
        else locks[vals]++;
    }
    int res=0;
    for(auto i = keys.begin(); i != keys.end(); i++){
        for(auto j = locks.begin(); j != locks.end(); j++) {
            auto [vec_1, val_1] = *i;
            auto [vec_2, val_2] = *j;
            bool is = true;
            for(int k=0; k<5; k++){
                if(vec_1[k] + vec_2[k] > 5) is = false;
            }

            res += val_1*val_2*is;
        }
    }
    cout << res;
}
