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

    robot(){
        pos='A';
    }
};

pi co(char x){
    if(x == '^') return {-1, 0};
    if(x == '>') return {0, 1};
    if(x=='v') return {1, 0};
    if(x=='<') return {-1, 0};
}

struct state{
    array<robot, 4> A;
    pi numpad;
    string res;
    int dist;
};
inline bool operator<(const state &lhs, const state &rhs){
    return lhs.dist > rhs.dist;
}

struct vis_state{
    pi numpad;
    string res;
};

inline bool operator<(const vis_state &lhs, const vis_state &rhs){
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

pi from_num(char x){
    if(x == 'A') return {3 + '0', 2+ '0'};
    if(x == '0') return {3 + '0', 1+ '0'};
    if(x>='1' && x <='3') return {2 + '0', x-1};
    if(x>='4' && x <='6') return {1 + '0', x-4};
    if(x>='7' && x <='9') return {0 + '0', x-7};

}

bool num_legal(pi num){
    return (num.first <4 && num.first >=0 && num.second >=0 && num.second <3 
    && (num.first != 3 || num.second != 0));
}

void print(map<pi, int> A){
    for(int i=-4; i<=4; i++) {
        for(int j=-4; j<=4; j++){
            cout << A[{i,j}] << ' ';
            if(A[{i, j}] < 10) cout << ' ';
        }
        cout << '\n';
    }
}

pi cord_from_int(int x){
    if(x==0) return {0, 1};
    if(x==1) return {0, 2};
    if(x==2) return {1, 0};
    if(x==3) return {1, 1};
    if(x==4) return {1, 2};
    assert(2==1);
}

int int_from_pair(pi x){
    auto [a, b] = x;
    if(a == 0 && b == 1) return 0;
    if(a == 0 && b == 2) return 1;
    if(a == 1 && b == 0) return 2;
    if(a == 1 && b == 1) return 3;
    if(a == 1 && b == 2) return 4;
    return -1;
}

pi dir_from_int(int x){
    if(x == 0) return {-1, 0};
    if(x == 1) {assert(1==2); return {0, 0};}
    if(x == 2) return {0, -1};
    if(x == 3) return {1, 0};
    if(x == 4) return {0, 1};
    assert(1==2);
}

int int_from_dir(pi x){
    auto [a, b] = x;
    if(a == -1) return 0;
    if(b == -1) return 2;
    if(a == 1) return 3;
    if(b == 1) return 4;
    return 1;

}

signed meow() {
    //bfs

    int t = 5;

    vector<vector<int>> G(5, vector<int> (5, 1));


    for(int ___i=0; ___i<25; ___i++){
        vector<vector<int>> next(5, vector<int> (5, LLONG_MAX));
        for(int i=0; i<5; i++) next[i][i] = 1;

        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++) {
                if(i == j) continue;


                auto start_coord = cord_from_int(i);
                auto end_coord = cord_from_int(j);
                if(start_coord.first == end_coord.first) {
                    next[i][j] = 
                        start_coord.second > end_coord.second ? 
                        G[1][int_from_dir({0, -1})] + start_coord.second 
                        - end_coord.second -1 + G[int_from_dir({0, -1})][1] :
                        G[1][int_from_dir({0, 1})] - start_coord.second 
                        + end_coord.second -1 + G[int_from_dir({0, 1})][1];
                    continue;
                } 
                if(start_coord.second == end_coord.second) {
                    next[i][j] =
                        start_coord.first > end_coord.first ? 
                        G[1][int_from_dir({-1, 0})] + start_coord.first 
                        - end_coord.first -1 + G[int_from_dir({-1, 0})][1] :
                        G[1][int_from_dir({1, 0})] - start_coord.first 
                        + end_coord.first -1 + G[int_from_dir({1, 0})][1];
                    
                    continue;
                }

                pi vec; 
                vec.first = end_coord.first - start_coord.first;
                vec.second = end_coord.second - start_coord.second;

                if(vec.first > 0 && vec.second > 0) {
                    next[i][j] = min(
                        G[1][int_from_dir({0, 1})] + abs(vec.first) - 1 
                        + G[int_from_dir({0, 1})][int_from_dir({1, 0})]
                        + abs(vec.second) - 1 + G[int_from_dir({1, 0})][1] ,

                        G[1][int_from_dir({1, 0})] + abs(vec.first) - 1 
                        + G[int_from_dir({1, 0})][int_from_dir({0, 1})]
                        + abs(vec.second) - 1 + G[int_from_dir({0, 1})][1] 
                    );
                    continue;
                }

                if(vec.first < 0 && vec.second > 0) {
                    int tt = (start_coord.second == 0 && end_coord.first == 0);
                    next[i][j] = min(
                        G[1][int_from_dir({0, 1})] + abs(vec.first) - 1 
                        + G[int_from_dir({0, 1})][int_from_dir({-1, 0})]
                        + abs(vec.second) - 1 + G[int_from_dir({-1, 0})][1],

                        G[1][int_from_dir({-1, 0})] + abs(vec.first) - 1 
                        + G[int_from_dir({-1, 0})][int_from_dir({0, 1})]
                        + abs(vec.second) - 1 + G[int_from_dir({0, 1})][1] + tt*(LLONG_MAX/4)
                    );
                    continue;
                }

                if(vec.first > 0 && vec.second < 0) {
                    int tt = !(start_coord.first == 0 && end_coord.second == 0);
                    next[i][j] = min(
                    tt*(G[1][int_from_dir({0, -1})] + abs(vec.first) - 1 
                        + G[int_from_dir({0, -1})][int_from_dir({1, 0})]
                        + abs(vec.second) - 1 + G[int_from_dir({1, 0})][1]) + LLONG_MAX/5 * !tt,

                        G[1][int_from_dir({1, 0})] + abs(vec.first) - 1 
                        + G[int_from_dir({1, 0})][int_from_dir({0, -1})]
                        + abs(vec.second) - 1 + G[int_from_dir({0, -1})][1] 
                    );
                    continue;
                }

                if(vec.first < 0 && vec.second < 0) {
                    next[i][j] = min(
                        G[1][int_from_dir({0, -1})] + abs(vec.first) - 1 
                        + G[int_from_dir({0, -1})][int_from_dir({-1, 0})]
                        +abs(vec.second) - 1 + G[int_from_dir({-1, 0})][1],

                        (G[1][int_from_dir({-1, 0})] + abs(vec.first) - 1 
                        + G[int_from_dir({-1, 0})][int_from_dir({0, -1})]
                        +abs(vec.second) - 1 + G[int_from_dir({0, -1})][1] )
                    );
                    continue;
                }
            }
        }
        G = next;
    }


    while(t--){
        string S; cin >> S;
        int res = 0;
        pi curr = {3, 2};
        for(auto s : S){
            pi tmp = from_num(s);

            tmp.first -= '0'; tmp.second -= '0';
            pi vec; 
            vec.first = tmp.first - curr.first;
            vec.second = tmp.second - curr.second;

            int val=0;
            if(vec.first < 0 && vec.second < 0) {
                int tt = 1;
                if(tmp.second == 0 && curr.first == 3) tt = 0;
                val = min(
                    G[1][int_from_dir({-1,0})] + G[int_from_dir({-1,0})][int_from_dir({0,-1})]  + G[int_from_dir({0,-1})][1] -1 + abs(vec.first) + abs(vec.second)-1 ,
                tt*(G[1][int_from_dir({0,-1})] + G[int_from_dir({0,-1})][int_from_dir({-1,0})]  + G[int_from_dir({-1,0})][1] -1 + abs(vec.first) + abs(vec.second))-1
                 + LLONG_MAX/5 * !tt);
            }
            if(vec.first > 0 && vec.second < 0) {
                val = min(
                    G[1][int_from_dir({1,0})]  + G[int_from_dir({1,0})] [int_from_dir({0,-1})] + G[int_from_dir({0,-1})][1] -1 + abs(vec.first) + abs(vec.second)-1 ,
                    G[1][int_from_dir({0,-1})] + G[int_from_dir({0,-1})] [int_from_dir({1,0})] + G[int_from_dir({1,0})][1]  -1 + abs(vec.first) + abs(vec.second)-1);
            }
            if(vec.first < 0 && vec.second > 0) {
                cerr << G[1][int_from_dir({-1,0})] + G[int_from_dir({-1,0})][int_from_dir({0,1})] + G[int_from_dir({0,1})][1] -1 + abs(vec.first) + abs(vec.second) << '\n' <<
                G[1][4] + G[4][0] + G[0][1] -1 + abs(vec.first) + abs(vec.second);
                val = min(
                    G[1][int_from_dir({-1,0})] -1 + abs(vec.first)+ G[int_from_dir({-1,0})][int_from_dir({0,1})] -1 + abs(vec.second) + G[int_from_dir({0,1})][1],
                    G[1][int_from_dir({0,1})] + G[int_from_dir({0,1})][int_from_dir({-1,0})] + G[int_from_dir({-1,0})][1] -1 + abs(vec.first) + abs(vec.second)-1);
            }

            if(vec.first > 0 && vec.second > 0) {
                int tt = 1;
                if(curr.second == 0 && tmp.first == 3) tt = 0;
                val = min(
                tt*(-1+G[1][int_from_dir({1,0})] + G[int_from_dir({1,0})][int_from_dir({0,1})] + G[int_from_dir({0,1})][1] -1 + abs(vec.first) + abs(vec.second)) + LLONG_MAX/5 * !tt,
                    G[1][int_from_dir({0,1})] + G[int_from_dir({0,1})][int_from_dir({1,0})] + G[int_from_dir({1,0})][1] -1 + abs(vec.first) + abs(vec.second)-1);
            }

            if(vec.first == 0 && vec.second < 0){
                val = G[1][int_from_dir({0,-1})] + G[int_from_dir({0,-1})][1] -1 + abs(vec.second);
            }

            if(vec.first == 0 && vec.second > 0){
                val = G[1][int_from_dir({0,1})] + G[int_from_dir({0,1})][1] -1 + abs(vec.second);
            }

            if(vec.first < 0 && vec.second == 0){
                val = G[1][int_from_dir({-1, 0})] + G[int_from_dir({-1, 0})][1] -1 + abs(vec.first);
            }

            if(vec.first > 0 && vec.second == 0){
                val = G[1][int_from_dir({1, 0})] + G[int_from_dir({1, 0})][1] -1 + abs(vec.first);
            }

            res += val;


            curr = tmp;
        }

        cout << res << '\n';
    }
    
}