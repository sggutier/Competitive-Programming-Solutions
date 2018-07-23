#include <bits/stdc++.h>
#define fs first
#define sn second
using namespace std;
typedef pair <int, int> pii;
typedef tuple<int, int, int, int> est;

const int INF = 1e9;

int di[] = {-1, 0, 0, 0, 1},
	dj[] = {0, -1, 0, 1, 0};

int N, M, P, MD = 1;
bitset <50000> ANS[65][65];
pii S, T;
vector<pii> PT[205];
char MP[65][65];
int SM[65][65];

int getSum(int li, int lj, int mi, int mj) {
	int ans = SM[mi][mj];
	if(li) ans -= SM[li-1][mj];
	if(lj) ans -= SM[mi][lj-1];
	if(li && lj) ans += SM[li-1][lj-1];
	return ans;
}

bool inside(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

pii getPT(int id, int t) {
	int L = PT[id].size();
	if(L!=1)
		t %= 2 * (L - 1);
	else
		t = 0;
	
	return (t < L) ? PT[id][t] : PT[id][2 * L - 2 - t];
}

bool is_free(int i, int j, int tm) {
	for(int k=0;k<P;k++) {
		pii pt = getPT(k, tm);
		
		int ilo = min(pt.fs, i), 
			ihi = max(pt.fs, i),
			jlo = min(pt.sn, j),
			jhi = max(pt.sn, j);
		
		if((pt.fs == i || pt.sn == j) &&
			getSum(ilo,jlo, ihi,jhi) == 0)
			return false;
	}
	
	return true;
}

pii leePar() {
	char c ;
	do {
		scanf("%c", &c);
		//~ printf("-- %c\n", c);
	} while( c != '(');
	int a, b ;
	scanf("%d%d", &a, &b);
	scanf("%c", &c);
	return {a - 1, b - 1 };
}

int main() {
	scanf("%d %d", &N, &M);
	S = leePar();
	T = leePar();
	
	for(int i=0;i<N;i++)
		scanf("%s", MP[i]);
		
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			SM[i][j] = MP[i][j] == '#';
			
			if(i) SM[i][j] += SM[i-1][j];
			if(j) SM[i][j] += SM[i][j-1];
			if(i && j) SM[i][j] -= SM[i-1][j-1];
		}
	}
		
	scanf("%d", &P);
	
	for(int i=0;i<P;i++) {
		int Ps; scanf("%d", &Ps);
		PT[i].resize(Ps);
		
		for(int j=0;j<Ps;j++)
			PT[i][j] = leePar();
			
		int Qs = 2 * Ps - 2;
		if(Ps == 1)
			Qs = 1;
		//~ printf("=> %d\n", Qs);
		MD = MD * Qs / __gcd(MD, Qs);
	}	
	//~ printf("%d\n", MD);
				
	ANS[S.fs][S.sn][0] = true;
				
	queue< est > q;
	q.push(est(S.fs, S.sn, 0, 0));
	
	while(!q.empty()) {
		int i, j, tm, t;
		tie(i, j, tm, t) = q.front(); q.pop();
		
		if(make_pair(i, j) == T) {
			printf("%d\n", t);
			return 0;
		}
			
		for(int k=0;k<5;k++) {
			int ni  = i + di[k],
				nj  = j + dj[k],
				ntm = (tm + 1) % MD,
				nt  = t + 1;
				
			if (!inside(ni, nj) || MP[ni][nj] == '#')
				continue;
				
			if (!is_free(ni, nj, ntm) && make_pair(ni, nj) != T)
				continue;
				
			if (!ANS[ni][nj][ntm]) {
				ANS[ni][nj][ntm] = true;
				q.push(est(ni, nj, ntm, nt));
			}
		}
	}
		
	printf("IMPOSSIBLE\n");
}

