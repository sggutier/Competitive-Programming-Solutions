#include <bits/stdc++.h>
using namespace std;
const int limN = 805;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
typedef pair<int,int> pii;
#define r first
#define c second

int R, S;
char mapa[limN][limN];
int minPBees[limN][limN];
int minPBear[limN][limN];
int iniT = 0;

void bfs(vector<pii> &iniPoss, int minP[limN][limN], function<bool(pii&, const int)> isPosValid) {
	for(int i=0; i < R; i++) {
		for(int j = 0; j < R; j++) {
			minP[i][j] = -1;
		}
	}
	queue <pii> Q;
	for(auto ini : iniPoss) {
		Q.push(ini);
		minP[ini.r][ini.c] = 0;
	}
	while(!Q.empty()) {
		pii pos = Q.front(); Q.pop();
		int dst = minP[pos.r][pos.c] + 1;
		for(int d=0; d < 4; d++) {
			pii sig = {pos.r + dr[d], pos.c + dc[d]};
			if(!isPosValid(sig, dst)) {
				continue;
			}
			Q.push(sig);
			minP[sig.r][sig.c] = dst;
		}
	}
}

bool insideLimits(pii &pos) {
	return 0 <= pos.r && pos.r < R && 0 <= pos.c && pos.c < R;
}

bool beeCheck(pii &pos, const int _dst) {
	if(!insideLimits(pos) || minPBees[pos.r][pos.c] != -1) {
		return false;
	}
	return mapa[pos.r][pos.c] == '.';
}

bool bearCheck(pii &pos, const int dst) {
	if(!insideLimits(pos) || minPBear[pos.r][pos.c] != -1) {
		return false;
	}
	if(mapa[pos.r][pos.c] == '#') {
		return false;
	}
	int bdst = minPBees[pos.r][pos.c];
	if(bdst == -1) {
		return true;
	}
	return dst / S + iniT < bdst ;
}

void testCase() {
	vector <pii> bearPos;
	vector <pii> beePos;
	pii home;
	scanf("%d", &R);
	for(int i=0; i < R; i++) {
		scanf("%s", mapa[i]);
		for(int j = 0; j < R; j++) {
			if(mapa[i][j] == 'T') {
				mapa[i][j] = '.';
				bearPos.emplace_back(i, j);
			}
			else if(mapa[i][j] == 'O') {
				home = pii(i, j);
			}
			else if(mapa[i][j] == 'F') {
				beePos.emplace_back(i, j);
			}
		}
	}
	scanf("%d", &S);
	bfs(beePos, minPBees, beeCheck);
	int ini = 0, fin = R*R;
	if(minPBees[bearPos[0].r][bearPos[0].c] != -1) {
		fin = minPBees[bearPos[0].r][bearPos[0].c] - 1;
	}
	while(ini < fin) {
		int piv = (ini + fin) / 2 + 1;
		iniT = piv;
		bfs(bearPos, minPBear, bearCheck);
		if(minPBear[home.r][home.c] == -1) {
			fin = piv -1;
		}
		else {
			ini = piv ;
		}
	}
	iniT = ini;
	bfs(bearPos, minPBear, bearCheck);
	if(minPBear[home.r][home.c] == -1) {
		ini = -1;
	}
	printf("%d\n", ini);
}

int main() {
	testCase();
}
