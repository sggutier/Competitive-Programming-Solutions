#include <bits/stdc++.h>
using namespace std;
const int ALF_SIZ = 28;
const int LIM_N = 40005;

inline int toId(const char x) {
    return isalpha(x)? x - 'a' : (x=='#'? 26 : 27);
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

    SuffixAutomata(const string s) {
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

SuffixAutomata *sa;
int waysEnd[LIM_N][2];
bool usd[LIM_N];
int ans = LIM_N;

void dp(const int pos = 0) {
    if(usd[pos]) return;
    usd[pos] = true;
    if(sa->states[pos].next.count(26))
        waysEnd[pos][0] = 1;
    if(sa->states[pos].next.count(27))
        waysEnd[pos][1] = 1;
    for(const auto &p : sa->states[pos].next) {
        if(p.first > 25) continue;
        int nxt = p.second;
        dp(nxt);
        waysEnd[pos][0] = min(2, waysEnd[pos][0] + waysEnd[nxt][0]);
        waysEnd[pos][1] = min(2, waysEnd[pos][1] + waysEnd[nxt][1]);
    }
    // printf("%d => %d %d\n", pos, waysEnd[pos][0], waysEnd[pos][1]);
    // for(int i=0; i < 28; i++) {
    //     printf("\t%c => %d\n", i < 26? i + 'a' : (i==26? '#' : '$'), sa->states[pos].next[i]);
    // }
}

void dfs(const int pos = 0, const int dep = 0) {
    if(dep && waysEnd[pos][0] == 1 && waysEnd[pos][1] == 1)
        ans = min(ans, dep);
    for(const auto &p : sa->states[pos].next) {
        if(p.first > 25) continue;
        int nxt = p.second;
        dfs(nxt, dep + 1);
    }
}

int main() {
    int N, M ;
    char s[LIM_N];
    scanf("%s", s);
    N = strlen(s);
    s[N] = '#';
    scanf("%s", (s + N + 1));
    M = strlen(s + N + 1);
    (s + N + 1)[M] = '$';
    sa = new SuffixAutomata(s);
    dp();
    dfs();
    printf("%d\n", ans==LIM_N? -1 : ans);
}
