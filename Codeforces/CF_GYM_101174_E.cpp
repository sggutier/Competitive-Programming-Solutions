#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
#define fs first
#define sn second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int limW = 25;
const int limN = 1005;
const int mod = 1e6 + 3;
bool usd[limW][limN][8];
int dp[limW][limN][8];
bool dgt[26];

struct AhoCorasick {
	enum {alpha = 26, first = 'a' };
	
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
	
};

AhoCorasick *A;

int ways(int rem, int pos=0, int msk=0) {
	if(A->N[pos].end != -1)
		return 0;
	if(rem==0)
		return msk==7? 1 : 0;
	if(usd[rem][pos][msk])
		return dp[rem][pos][msk];
	usd[rem][pos][msk] = true;
	int &ans = dp[rem][pos][msk];
	ans = (5 * ways(rem-1, 0, msk | 4)) % mod;
	for(int i=0; i<26; i++) {
		int sg = A->N[pos].next[i];
		ans = (ans + ways(rem-1, sg, msk|1) + ways(rem-1, sg, msk|2)) % mod;
		if(dgt[i])
			ans = (ans + ways(rem-1, sg, msk|4)) % mod;
	}
	return ans;
}

int main() {
	dgt['t'-'a'] = dgt['s'-'a'] = dgt['e'-'a'] = dgt['i'-'a'] =dgt['o'-'a'] = true;
	vector <string> wds;
	int mino, maxo;
	int N ;
	char tmp[limW];
	scanf("%d%d", &mino, &maxo);
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%s", tmp);
		wds.push_back(tmp);
	}
	A = new AhoCorasick(wds);
	int ans = 0;
	for(int i=mino; i<=maxo; i++)
		ans = (ans + ways(i)) % mod;
	printf("%d\n", ans);
}
