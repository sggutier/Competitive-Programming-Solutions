#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef pair<int, par> tri;
#define f first
#define s second
const int limM = 360;
const int limN = limM*limM;

int poso(const int x) {
	return min(x, 2);
}

set <tri> actvs;
list <tri> adj[limM];
int mdos ;

void ciclSta(const int pos, const int prev=-1) {
    
}

void testCase(int M) {
    for(int i=0; i<M; i++)
        adj[i].clear();
    actvs.clear();
    
	int N ;
	tri senc[limN];
	int ans = (1<<30);
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d%d%d", &senc[i].s.f, &senc[i].s.s, &senc[i].f);
	sort(senc, senc+N);
	
	for(int j=0; j<N; j++) {
		int x = senc[j].s.f, y = senc[j].s.s;
        adj[x].push_back(senc[j]);
        adj[y].push_back(senc[j]);
        mdos = 0;
        ciclSta(N);
		if(mdos==N)
			ans = min(ans, senc[j].f-senc[i].f);
	}
	
	printf("%d\n", ans);
}

int main() {
	int N ;
	while(scanf("%d", &N)!=EOF && N)
		testCase(N);
}
