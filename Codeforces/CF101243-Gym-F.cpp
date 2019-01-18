#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int N ;
vector <int> adj[limN], mens[limN], mays[limN], chld[limN];
int ldr[limN];
char cols[limN];

void dfs(int pos, const int l) {
	if(ldr[pos]) return;
	chld[l].push_back(pos);
	ldr[pos] = l;
	for(const int sig : adj[pos])
		dfs(sig, l);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int E ;
	scanf("%d", &N);
	scanf("%d", &E);
	vector <pair<int, int> > comps;
	for(int i=0; i<E; i++) {
		int a, b ;
		char c ;
		scanf("%d%c%d", &a, &c, &b);
		if(c=='=') {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		else {
			if(c == '>')
				swap(a, b);
			comps.push_back({a,b});
		}
	}
	
	for(int i=1; i<=N; i++)
		dfs(i, i);
		
	for(auto &p : comps) {
		int a = p.first, b = p.second;		
		a = ldr[a];
		b = ldr[b];
		//~ printf("%d < %d\n", a, b);
		mays[a].push_back(b);
		mens[b].push_back(a);
	}
	
	for(int i=1; i<=N; i++)
		cols[i] = '?';
	
	for(int i=1; i<=N; i++) {
		if(mens[i].empty() || mays[i].empty()) continue;
		cols[i] = 'R';
		for(const int a : mens[i])
			cols[a] = 'B';
		for(const int b : mays[i])
			cols[b] = 'W';
	}
	
	for(int i=1; i<=N; i++)
		for(const int c : chld[i])
			cols[c] = cols[i];
			
	printf("%s\n", cols + 1);
}
