#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, int> pli;
const int limN = 250000 + 5;

const int alfSiz = 26;
struct state {
	int length, slink = 0, next[26] = {0};
	bool end = false;
	
	state() {}
	state(int l) { length = l; }
	
	void copy(state &src) {
		for(int i=0;i<alfSiz;i++)
			next[i] = src.next[i];
	}
};

struct suffix_automata {
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
	
	suffix_automata(char *s) {
		states.push_back(state(0));
		states[0].slink = -1;
		
		for(char *c = s; *c; c++)
			extend(*c - 'a');
		
		int lst = last;
		
		while(lst != -1) {
			states[lst].end = true;
			lst = states[lst].slink;
		} 
	}

};


char lin[limN];

int main() {
    int N;
    fgets(lin, sizeof(lin), stdin);
    N = strlen(lin)-1;
    lin[N] = 0;
    suffix_automata sa(lin);
    fgets(lin , sizeof(lin), stdin);
    N = strlen(lin)-1;
    lin[N] = 0;

    int ans = 0;
    char *s = lin;
    for(int pos=0, w, l=0; *s; s++) {
        w = *s - 'a';
        while(pos && !sa.states[pos].next[w]) {
            pos = sa.states[pos].slink;
            l = min(l, sa.states[pos].length);
        }
        if(sa.states[pos].next[w]) {
            pos = sa.states[pos].next[w];
            l++;
        }
        // printf("%d %d\n", pos, l);
        ans = max(ans, l);
    }

    printf("%d\n", ans);
}
