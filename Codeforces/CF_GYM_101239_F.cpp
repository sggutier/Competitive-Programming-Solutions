#include <bits/stdc++.h>
using namespace std;
const int limN = 55;
const int limD = 4;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
typedef pair<int,int> pii;
#define r first
#define c second
const int inf = 1e9;
const int limMsg = 1e5 + 5;

int R, C ;
char mapa[limN][limN];
pii sigDir[limN][limN][limD];
int ids[300];
int W ;
int arUno[limN][limN], arDos[limN][limN];
vector <pii> inis[limN*3];
char msg[limMsg];

bool isValid(const pii sig) {
	return !(sig.r < 0 || R <= sig.r || sig.c < 0 || C <= sig.c);
}

void bfs(int iniP[limN][limN], int sigP[limN][limN], int idIni, int idSig) {
	
	int minD = 1e9;
	for(const pii &p : inis[idIni]) {
		minD = min(minD, iniP[p.r][p.c]);
	}
	//~ const int maxW = limN*5;
	priority_queue <pair<int, pii> > Q ;
	
	for(int i=0; i<R; i++)	
		for(int j=0; j<C; j++)
			sigP[i][j] = inf;
			
	for(const pii &p : inis[idIni]) {
		if(iniP[p.r][p.c] != inf) {
			sigP[p.r][p.c] = iniP[p.r][p.c];
			Q.push({-iniP[p.r][p.c], p});
		}
	}
		
	while(!Q.empty()) {
		pii p = Q.top().c;
		int w = -Q.top().r;
		Q.pop();
		if(sigP[p.r][p.c] < w) continue ;
		w ++;
		for(int d = 0; d<limD; d++) {
			pii q = sigDir[p.r][p.c][d];
			if(!isValid(q) || sigP[q.r][q.c] <= w) continue;
			Q.push({-w, q});
			sigP[q.r][q.c] = w;
		}
	}
}

pii calcDir(pii pos, const int d) {
	char c = mapa[pos.r][pos.c];
	const pii ans = pos;
	for(; isValid(pos); pos.r += dr[d], pos.c += dc[d])
		if(mapa[pos.r][pos.c] != c)
			return pos;
	return ans;
} 

int main() {
	for(int i='A'; i<='Z'; i++)
		ids[i] = W++;
	for(int i='0'; i<='9'; i++)
		ids[i] = W++;
	ids['-'] = W++;
	ids['*'] = W++;
	
	scanf("%d%d", &R, &C);
	for(int i=0; i<R; i++) {
		scanf("%s", mapa[i]);
		for(int j=0; j<C; j++) {
			inis[ ids[(int) mapa[i][j]] ].push_back({i, j});
			arDos[i][j] = inf;
			arUno[i][j] = inf;
		}
	}
	scanf("%s", msg);
	
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			for(int d=0; d<4; d++)
				sigDir[i][j][d] = calcDir({i, j}, d);
	
	auto x = arUno, y = arDos;
		
	x[0][0] = 0;
	int L = strlen(msg);
	msg[L++] = '*';
	
	char pv = mapa[0][0];
	for(int i=0; i<L; i++) {
		//~ printf("de %c a %c\n", msg[i-1], msg[i]);
		bfs(x, y, ids[(int) pv], ids[(int) msg[i]]);
		pv = msg[i];
		swap(x, y);
	}
	
	int ans = inf;
	for(int i=0; i<R; i++)	
		for(int j=0; j<C; j++)
			if(mapa[i][j] == '*')
				ans = min(ans, x[i][j]);
	
	printf("%d\n", ans + L);
}
