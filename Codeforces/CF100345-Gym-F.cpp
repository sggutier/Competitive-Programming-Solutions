#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
typedef long long ll;

bool gana[limN];
vector <int> otr;

void generaPerds(ll fin) {
	ll p=2, dif=2;
	while(p <= fin) {
		otr.push_back(p);
		if(p + dif >= dif*dif)
			dif ++;
		p += dif;
	}
}

int main() {
	//~ int n ;
	//~ scanf("%d", &n);
	//~ vector <int> perds;
	//~ for(int i=1; i<=n; i++) {
		//~ for(int j=1; j*j<=i; j++) {
			//~ if(!gana[i-j]) {
				//~ gana[i] = true;
				//~ printf("%d gana con %d\n", i, j);
				//~ break;
			//~ }
		//~ }
		//~ printf("%2d => %s\n", i, gana[i]? "WIN" : "LOSE");
		//~ if(!gana[i])
			//~ perds.push_back(i);
	//~ }
	//~ generaPerds(n);
	//~ printf("%d ||| %d\n", (int) otr.size(), (int) perds.size());
	//~ for(int i=0; i<(int) otr.size(); i++) {
		//~ if(i > (int) perds.size() || otr[i] != perds[i]) {
			//~ printf("Nope, %d no esta en las buenas\n", otr[i]);
		//~ }
	//~ }
	//~ printf("Hay un total de %d\n", (int) perds.size());
	//~ for(int i=0; i<(int) perds.size(); i++) {
		//~ if(i)
			//~ printf("Dif es %d ", perds[i] - perds[i-1]);
		//~ printf("%d\n", perds[i]);
	//~ }
	//~ printf("\n");
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	ll n ;
	scanf("%lld", &n);
	ll p=2, dif=2;
	while(p < n) {
		//~ otr.push_back(p);
		if(p + dif >= dif*dif)
			dif ++;
		p += dif;
	}
	printf("%s\n", p==n? "LOSE" : "WIN");
}
