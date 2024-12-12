#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

int dfs(int a, int k){
    if(k==0) 
        return 1;

    if(a==0) return dfs(1, k-1);
    int n=0;
    int pow = 1;
    int a_ = a;
    while(a/pow != 0) {
        pow*=10;
        n++;
    }

    if(n%2 == 0) {

        pow=sqrt(pow);
        return dfs(a/pow, k-1) + dfs(a%pow, k-1);
    }

    return dfs(a*2024, k-1);
}
signed meow() {
    int res=0;
    vector<int> A = {28, 4, 3179, 96938, 0, 6617406, 490, 816207};
   //vector<int> A = {125, 17};
    for(auto &a : A) 
        res += dfs(a, 25);

    cout << res << '\n';

}
