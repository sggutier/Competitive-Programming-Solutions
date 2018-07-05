#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
#define fs first
#define sn second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int T, L, C, W;
char MP[2005][2005];
char buff[2005];
vector<string> pat;
vector<pair<pii, char>> res;

int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 },
	dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	
bool inside(int i, int j) { return 0 <= i && i < L && 0 <= j && j < C; }

struct AhoCorasick {
	enum {alpha = 26, first = 'A' };
	
	struct Node {
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	
	vector <Node> N;
	vector <int> backp;
	
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		trav(c, s) {
			int& m = N[n].next[c - first];
			if(m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if(N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
	
	AhoCorasick(vector<string>& pat) {
		N. emplace_back(-1);
		rep(i, 0, sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);
		
		queue<int> q;
		
		for(q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i, 0, alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if(ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) =
						N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	
	void find(int i, int j) {
				
		for(int k=0;k<8;k++) {
			int pi = i - di[k],
				pj = j - dj[k];
			
			if(inside(pi, pj)) continue;
			
			int n = 0;
			
			int ci = i, cj = j;
			
			while(inside(ci, cj)) {
				char c = MP[ci][cj];
				
				n = N[n].next[c - first];
				
				if(N[n].end != -1) {
					int ed = N[n].end;
					
					res[ed] = {
						{
							ci - (pat[ed].size() - 1) * di[k],
							cj - (pat[ed].size() - 1) * dj[k]
						}, 
						k + 'A'
					};
				}
				
				ci += di[k], cj += dj[k];
			}
		}
	}
	
	void find() {				
		for(int j=0;j<C;j++) {
			find(0, j);
			find(L - 1, j);
		}
		
		for(int i=1;i<L-1;i++) {
			find(i, 0);
			find(i, C - 1);
		}
	}
	
};

int main() {	
	scanf("%d", &T);
	
	while(T--) {
		scanf("%d %d %d", &L, &C, &W);
		
		for(int i=0;i<L;i++)
			scanf("%s", MP[i]);
		
		pat.resize(W);
		res.resize(W);
		
		for(int i=0;i<W;i++) {
			scanf("%s", buff);
			pat[i] = buff;
		}
		
		AhoCorasick aho(pat);			
				
		aho.find();
				
		for(auto el : res) 
			printf("%d %d %c\n", el.fs.fs, el.fs.sn, el.sn);
			
		if(T) printf("\n");
	}	
}
 
