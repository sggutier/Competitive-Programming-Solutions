#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int alfSiz = 28;
struct state {
	int length, slink = 0, next[28] = {0};
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
	
	suffix_automata(string &s) {
		states.push_back(state(0));
		states[0].slink = -1;
		
		for(char c : s) 
			extend(c - 'a');
		
		int lst = last;
		
		while(lst != -1) {
			states[lst].end = true;
			lst = states[lst].slink;
		} 
	}

};


const int limN = 300 * 5 + 5;

bool usd[limN];
int dp[limN];
vector <state> sa;
bool ra[limN], rb[limN];

void consi(int pos) {
    if(usd[pos]) return;
    usd[pos] = true;
    if(sa[pos].next[26])
        ra[pos] = true;
    if(sa[pos].next[27])
        rb[pos] = true;
    for(int i=0, w; i<26; i++) {
        w = sa[pos].next[i];
        if(w) {
            consi(w);
            ra[pos] |= ra[w];
            rb[pos] |= rb[w];
        }
    }
}

int memo(int pos) {
    if(usd[pos]) return dp[pos];
    usd[pos] = true;
    int &ans = dp[pos];
    if(!ra[pos] || !rb[pos]) {
        return ans = -2;
    }
    ans = 0;
    for(int i=0; i<26; i++)
        if(sa[pos].next[i])
            ans = max(ans, 1 + memo(sa[pos].next[i]));
    return ans;
}

int W = 0;
char ans[limN];

void reconstr(int pos) {
    if(dp[pos] == 0) {
        printf("%s\n", ans);
        return ;
    }
    for(int i=0, w; i<26; i++) {
        w = sa[pos].next[i];
        if(w && dp[w] == dp[pos]-1) {
            ans[W++] = i + 'a';
            reconstr(w);
            ans[--W] = 0;
        }
    }
}

char T[limN];

void testCase() {
    
    memset(ra, 0, sizeof(ra));
    memset(rb, 0, sizeof(rb));
    int n = (int)strlen(T);
    T[n++] = 'a' + 26;
    scanf("%s", T + n);
    int m = strlen(T+n);
    n += m;
    T[n++] = 'a' + 27;

    string s = T;
    sa = suffix_automata(s).states;
    memset(usd, 0, sizeof(usd));
    consi(0);
    memset(usd, 0, sizeof(usd));

    if(memo(0))
        reconstr(0);
    else
        printf("No common sequence.\n");
}

int main() {
    int tc = 0;
    while(scanf("%s", T)!=EOF) {
        if(tc++)
            printf("\n");
        testCase();
        memset(T, 0, sizeof(T));
    }
}
