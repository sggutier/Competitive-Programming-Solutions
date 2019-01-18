#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int dep[limN];
vector<int> adj[limN];
bool usd[limN], gana[limN];

void bfs() {
	queue <int> Q ;
	Q.push(1);
	dep[1] = 1;
	while(!Q.empty()) {
		int pos = Q.front();
		Q.pop();
		for(const int sig : adj[pos]) if(!dep[sig]) {
			dep[sig] = dep[pos] + 1;
			Q.push(sig);
		}
	}
}

bool memo(int pos) {
	if(usd[pos]) return gana[pos];
	usd[pos] = true;
	for(const int sig : adj[pos]) {
		if(dep[sig] > dep[pos] && !memo(sig)) {
			//~ printf("%d => %d %d\n", pos, dep[pos], 1);
			return gana[pos] = true;
		}
	}
			//~ printf("%d => %d %d\n", pos, dep[pos], 0);
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, E;
	scanf("%d%d", &N, &E);
	for(int i=0, a, b; i<E; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	bfs();
	
	printf("%s\n", memo(1)? "Vladimir" : "Nikolay");
}
