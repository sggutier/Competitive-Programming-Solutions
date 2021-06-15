#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ALF_SIZ = 26;
const int LIM_N = 1e5 + 5;

inline int toId(const char x) {
    return isalpha(x)? x - 'a' : ALF_SIZ + 1;
}

struct state {
    int length, slink = 0;
    map<int,int> next ;
    bool end = false;

    state() {}
    state(int l) { length = l; }

    void copy(state &src) {
        next = src.next;
    }
};

struct SuffixAutomata {
    vector<state> states;
    int last = 0;

    void extend(int c) {
        int new_state = states.size();
        states.push_back(state(states[last].length + 1));

        int p = last;
        last = new_state;

        while(p != -1 && states[p].next[c] == 0) {
            states[p].next[c] = new_state;
            p = states[p].slink;
        }

        if(p != -1) {
            int q = states[p].next[c];

            if(states[p].length + 1 == states[q].length)
                states[new_state].slink = q;
            else {
                int clone = states.size();

                states.push_back(state(states[p].length + 1));
                states[clone].copy(states[q]);
                states[clone].slink = states[q].slink;

                while(p != -1 && states[p].next[c] == q) {
                    states[p].next[c] = clone;
                    p = states[p].slink;
                }

                states[q].slink = clone;
                states[new_state].slink = clone;
            }
        }
    }

    SuffixAutomata(const string &s) {
        states.push_back(state(0));
        states[0].slink = -1;

        for(char c : s)
            extend(toId(c));

        int lst = last;

        while(lst != -1) {
            states[lst].end = true;
            lst = states[lst].slink;
        }
    }
};

inline ll gauss(const ll n) {
    return (n*(n+1)) >> 1;
}

SuffixAutomata *sa;
ll dp[LIM_N * 4], waysEnd[LIM_N * 4];
bool usd[LIM_N * 4];

void memo(const int pos) {
    if(usd[pos])
        return ;
    usd[pos] = true;
    if(sa->states[pos].next.empty()) {
        waysEnd[pos] = 1;
        return ;
    }
    for(const auto &p : sa->states[pos].next) {
        memo(p.second);
        dp[pos] += dp[p.second] ;
        waysEnd[pos] += waysEnd[p.second];
    }
    dp[pos] += gauss(waysEnd[pos]);
    // printf("%d => %lld %lld\n", pos, dp[pos], waysEnd[pos]);
    // for(const auto &p : sa->states[pos].next) {
    //     printf("\t%c %d | %lld %lld\n", p.first < ALF_SIZ? p.first + 'a' : '$', p.second, dp[p.second], waysEnd[p.second]);
    // }
}

int main() {
    cin.sync_with_stdio();
    string S ;
    cin >> S ;
    sa = new SuffixAutomata(S + "$");
    memo(0);
    printf("%lld\n", dp[0] - gauss(waysEnd[0]));
}
