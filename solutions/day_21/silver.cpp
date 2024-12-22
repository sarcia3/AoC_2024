#include "bits/stdc++.h"
#define int long long
#define pi pair<long long, long long>
#define a3 array<long long, 3>

#define meow main

using namespace std;

struct robot{
    char pos;

    set<char> get_moves(){
        if(pos == '^') return {'A', 'v'};
        if(pos == 'A') return {'^', '>'};
        if(pos == '>') return {'A', 'v'};
        if(pos == 'v') return {'<', '^', '>'};
        if(pos =='<') return {'v'};

        return {};
    }

    bool make_dir_move(char x){
        if( x == '^'){
            if(pos == '>') pos = 'A';
            else if(pos == 'v') pos = '^';
            else return false;
        } else if(x == '>') {
            if(pos == '<') pos = 'v';
            else if(pos == 'v') pos = '>';
            else if(pos=='^') pos = 'A';
            else return false;
        } else if(x =='v'){
            if(pos == '^') pos = 'v';
            else if (pos=='A') pos = '>';
            else return 0;
        } else if(x == '<'){
            if(pos == 'A') pos = '^';
            else if(pos == '>') pos = 'v';
            else if(pos == 'v') pos = '<';
            else return false;
        }

        return true;
    }
};

pi co(char x){
    if(x == '^') return {-1, 0};
    if(x == '>') return {0, 1};
    if(x=='v') return {1, 0};
    if(x=='<') return {-1, 0};
}

struct state{
    robot first;
    robot second;
    pi numpad;
    string res;
    int dist;
};

struct vis_state{
    char first;
    char second;
    pi numpad;
    string res;
};

inline bool operator<(const vis_state &lhs, const vis_state &rhs){
    if(lhs.first != rhs.first) return lhs.first < rhs.first;
    if(lhs.second != rhs.second) return lhs.second < rhs.second;
    if(lhs.numpad != rhs.numpad) return lhs.numpad < rhs.numpad;
    return lhs.res < rhs.res;
}

char get_at_num(pi arg){
    auto [f, s] = arg;
    if(f==3 && s == 1) return '0';
    if(f==3 && s == 2) return 'A';
    
    if(f == 2) return '1' + s;
    if(f==1) return '4' +s;
    if(f==0) return '7' + s;
}

signed meow() {
    //bfs

    int t = 5;
    while(t--){
        queue<state> Q;
        Q.push({{'A'}, {'A'}, {3, 2}, "", 0});
        set<vis_state> vis;
        string s; cin >> s;
        while(!Q.empty()){
            auto [fst, snd, num, res, d] = Q.front(); Q.pop();
            if(res==s){
                cout << d << '\n';
                break;
            }
            if(vis.count({fst.pos, snd.pos, num, res})) continue;
            if(s.substr(0, res.size()) != res) 
                continue;
            vis.insert({fst.pos, snd.pos, num, res});
            for(auto move : fst.get_moves()){
                state tmp = {fst, snd, num, res, d+1};
                tmp.first.pos = move;
                if(!vis.count({tmp.first.pos, tmp.second.pos, num, res}))
                    Q.push(tmp);
            }

            if(fst.pos == 'A'){
                if(snd.pos == 'A'){
                    res += get_at_num(num);
                    if(!vis.count({fst.pos, snd.pos, num, res}))
                        Q.push({fst, snd, num, res, d+1});
                } else {
                    if(snd.pos == '^') num.first--;
                    if(snd.pos == 'v') num.first++;
                    if(snd.pos == '<') num.second--;
                    if(snd.pos == '>') num.second++;
                    if(num.first <4 && num.first >=0 && num.second >=0 && num.second <3 && (num.first != 3 || num.second != 0)) {
                        if(!vis.count({fst.pos, snd.pos, num, res}))
                            Q.push({fst, snd, num, res, d+1});
                    }
                }
            } else if(snd.make_dir_move(fst.pos)) {
                if(!vis.count({fst.pos, snd.pos, num, res}))
                    Q.push({fst, snd, num, res, d+1});
            }
        }
    }
}