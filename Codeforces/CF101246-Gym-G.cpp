#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;
const int limE = 2e5 + 5;

int N ;
vector <int> adj[limN], g[limN];
int ans = 0;

int D = 1;
int ldr[limN], dfsId[limN], dfsMin[limN];
bool actv[limN];
int chld[limN];
stack <int> stk;

void tarjan(const int pos) {
	if(dfsId[pos]) 
		return;
	dfsId[pos] = dfsMin[pos] = D++;
	actv[pos] = true;
	stk.push(pos);
	for(const int sig : adj[pos]) {
		tarjan(sig);
		if(actv[sig])
			dfsMin[pos] = min(dfsMin[pos], dfsMin[sig]);
	}
	if(dfsId[pos] != dfsMin[pos])
		return;
	int sg ;
	do {
		sg = stk.top(); stk.pop();
		actv[sg] = false;
		chld[pos]++;
		ldr[sg] = pos;
	} while(sg != pos);
}


bool ida[limN][limN];
bool ven[limN][limN];

void dfs(const int pos) {
	if(actv[pos]) return ;
	actv[pos] = true;
	for(const int sig : g[pos]) {
		dfs(sig);
		for(int i=1; i<=N; i++)
			if(ida[sig][i]) {
				ida[pos][i] = true;
				//~ ven[i][pos] = true;
			}
	}
	ida[pos][pos] = true;
	//~ ven[pos][pos] = true;
}

int ls[limE], rs[limE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    
	int ans = 1 ;
	
	int E ;
	scanf("%d%d", &N, &E);
	for(int i=0, a, b; i<E; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		ls[i] = a;
		rs[i] = b;
	}
	
	for(int i=1; i<=N; i++)
		tarjan(i);
	for(int i=1; i<=N; i++) {
		for(const int sig : adj[i]) {
			g[ldr[i]].push_back(ldr[sig]);
		}
	}
	memset(actv, 0, sizeof(actv));	
	for(int i=1; i<=N; i++)
		if(ldr[i] == i)
			dfs(i);

			
	memset(actv, 0, sizeof(actv));
	vector <int> anums;
	for(int i=0; i<E; i++) {
		int a = ldr[ls[i]], b = ldr[rs[i]];
		int cnt = 0 ;
		for(int j=1; j<=N; j++) {
			if(ida[a][j] && ida[j][b]) {
				//~ if(i==0) {
					//~ printf("[%d] ", j);
				//~ }
				cnt += chld[j];
			}
		}
		//~ if(i==0)
			//~ printf("\n");
		if(cnt > ans) {
			anums.clear();
			ans = cnt;
		}
		if(cnt == ans)
			anums.push_back(i);
	}
	
	//~ for(int pos=1; pos<=N; pos++) {
		//~ if(ldr[pos] == pos) {
			//~ printf(">> %d\n", pos);
			//~ printf("\t");
			//~ for(int i=1; i<=N; i++)
				//~ if(ida[pos][i])
					//~ printf("%d ", i);
			//~ printf("\n");
		//~ }
	//~ }
	
	printf("%d\n", ans);
	int w = (int) anums.size();
	printf("%d\n", w);
	for(int i=0; i<w; i++)
		printf("%d%c", anums[i]+1, i==w-1? '\n' : ' ');
}
