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

const int limN = 2005;

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
	
	vi find(string word) {
		int n = 0;
		vi res;
		trav(c, word) {
			n = N[n].next[c-first];
			res.push_back(N[n].end);
		}
		return res;
	}
};

int golRows[limN];
int prevo[limN];
char matr[limN][limN];
vi anso[limN];
map <string, int> ordo;

void hazTabl(int *arr, int N, int *ant) {
	int i=-1, j=0;
	ant[0] = -1;
	while(j<N) {
		while(i!=-1 && arr[i] != arr[j])
			i = ant[i];
		i++, j++;
		ant[j] = i;
	}
}

int main() {
	vector <string> wds;
	int GR, GC;
	int N, M;
	char tmp[limN];
	string s ;
	scanf("%d%d", &GR, &GC);
	for(int i=0; i<GR; i++) {
		scanf("%s", tmp);
		s = tmp;
		auto it = ordo.find(s);
		if(it==ordo.end()) {
			golRows[i] = (int) wds.size();
			ordo[s] = golRows[i];
			wds.push_back(s);
		}
		else
			golRows[i] = it->second;
	}
	
	AhoCorasick A(wds);
	
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) {
		scanf("%s", matr[i]);
		anso[i] = A.find(matr[i]);
		//~ for(int j=0; j<M; j++)
			//~ printf("%d ", anso[i][j]);
		//~ printf("\n");
	}
	
	//~ printf("Golum es:\n\t");
	//~ for(int i=0; i<GR; i++)
		//~ printf("%d ", golRows[i]);
	//~ printf("\n");
	
	hazTabl(golRows, GR, prevo);
	
	for(int c=0; c<M; c++) {
		for(int i=0, j=0; j<N; j++) {
			while(i!=-1 && golRows[i] != anso[j][c])
				i = prevo[i];
			i++;
			if(i==GR) {
				i = prevo[i];
				matr[j][c] = 0;
			}
		}
	}
	
	int toto = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(!matr[i][j]) {
				printf("(%d,%d)\n", i-GR+2, j-GC+2);
				toto++;
			}
		}
	}
	if(!toto)
		printf("NO MATCH FOUND...\n");
}

