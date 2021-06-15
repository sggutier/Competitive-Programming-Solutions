#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool dfs(int a, int layer, const vector<vi> &g, vi& btoa,
vi& A, vi& B) {
	if (A[a] != layer) return 0 ;
	A[a] = -1;
	trav(b, g[a]) if (B[b] == layer+1) {
		B[b] = -1;
		if (btoa[b] == -1 || dfs(btoa[b], layer+2, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0 ;
}

int hopcroftKarp(const vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), -1);
		cur.clear();
		trav(a, btoa) if(a != -1) A[a] = -1;
		rep(a, 0, sz(g)) if(A[a] == 0) cur.push_back(a);
		for (int lay=1;; lay+=2) {
			bool islast = 0;
			next.clear();
			trav(a, cur) trav(b, g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && B[b] == -1) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			trav(a, next) A[a] = lay+1;
			cur.swap(next);
		}
		rep(a,0,sz(g)) {
			if(dfs(a, 0, g, btoa, A, B))
				++res;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, T ;
	string bus[205];
	int ls[205], rs[205];
	
	scanf("%d%d", &N, &T);
	T += N;
	vector <vi> g(T, vi());
	for(int i=0; i<T; i++) {
		char tmp[500];
		scanf("%s", tmp);
		bus[i] = tmp;
		
		ls[i] = tmp[0] + tmp[1] + tmp[2] - '0'*3;
		rs[i] = tmp[3] + tmp[4] + tmp[5] - '0'*3;
		//~ printf("%d %d\n", ls[i], rs[i]);
	}
	vi ba(T, -1);
	
	for(int i=0; i<N; i++) {
		for(int j=N; j<T; j++) {
			if(ls[i] == rs[j] || rs[i] == ls[j]) {
				g[i].push_back(j);
				g[j].push_back(i);
				//~ printf("%s y %s\n", bus[i].c_str(), bus[j].c_str());
			}
		}
	}
	
	int w = hopcroftKarp(g, ba);
	printf("%d\n", w/2);
	for(int i=0; i<N; i++) if(ba[i] != -1) {
		int j = ba[i];
		if(ls[i] == rs[j])
			printf("%s %s %s\n", ls[i] == rs[j]? "AT" : "TA", bus[i].c_str(), bus[j].c_str());
		else
			printf("%s %s %s\n", ls[i] == rs[j]? "AT" : "TA", bus[j].c_str(), bus[i].c_str());
	}
}

