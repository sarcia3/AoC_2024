/*



used this code to produce an output of sorted literal formulas for z_i
then after the assumption that all of them are of the form carry_{i-1} XOR (x_i XOR y_i)
looked through the output (resx.out means output after finding x pairs of errors)
and when I found formula for carry_i I just replaced it everwhere with carry_i
if the formula for carry or z was wrong I looked for a mistake.  iiinput.in was
the modefied input

^^



*/

#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>
#define a4 array<long long, 4>

#define meow main

using namespace std;

signed meow() {
    map<string, string> vals;
    map<string, int> _vals;
    map<string, int> cnt;
    vector<string> X;
    vector<string> Y;
    while(true){
        string s; cin >> s;
        if(s == "-1") break;
        int v; cin >> v;
        vals[s] = s;
        _vals[s] = 1;
        if(s[0] == 'x') X.push_back(s);
        if(s[0] == 'y') Y.push_back(s);
    }

    map<string, array<string, 3>> M;
    vector<string> swap_help;

    while(true){
        string a; cin >> a;
        if(a== "-1") break;
        string b; cin >> b;
        string c; cin >> c;
        string d; cin >> d;
        if(a > c) swap(a, c);
        M[d] = {a, b, c};
        swap_help.push_back(d);
        cnt[a]++;
        cnt[c]++;
        cnt[d]++;
    }

    function<string(string)> dfs = [&](string v){
        if(vals.count(v)) return vals[v];
        else if(M.count(v)){
            auto [a, b, c] = M[v];
            if(dfs(a) > dfs(c)) swap(a, c);
            return (vals[v] = "(" + dfs(a) + " " + b + " "+ dfs(c) +")");
        }
        return (string)"NULL";
    };

    function<int(string)> _dfs = [&](string v){
        if(vals.count(v)) return _vals[v];
        else {
            auto [a, b, c] = M[v];
            if(b == "AND") return (_vals[v] = _dfs(a) & _dfs(c));
            if(b == "OR") return (_vals[v] = _dfs(a) | _dfs(c));
            if(b == "XOR") return (_vals[v] = _dfs(a) ^ _dfs(c));
        }
        return (int)0;
    };

    unsigned long long res = 0;
    for(int i=0; i<99; i++){
        string tmp;
        tmp = "z";
        if(i<10) tmp.push_back('0');
        else tmp.push_back(i/10 + '0');
        tmp.push_back(i%10 + '0');
        cout << dfs(tmp) << '\n';
    }

    cout << res << '\n';
    
   /*vector<string> S = {"ckj", "dbp", "fdv", "rpp", "z15", "zdf", "z23", "z39"};
   sort(S.begin(), S.end());
   for(auto s : S) cout << s << ',';*/

}   