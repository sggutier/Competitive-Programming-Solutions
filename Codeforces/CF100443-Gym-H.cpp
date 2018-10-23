#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef int ll;
const ll mod = 21092013;

ll ways[limN];
int lenS, lenT;
int S[limN];
int T[limN];
int nextP[limN][2];
int mapo[300];

void procaS(char *a) {
	lenS = 0;
	for(; *a; a++) {
		if(*a == 'U')
			lenS = max(0, lenS-1);
		else
			S[lenS++] = mapo[(int) *a];
	}
}

void procaT(char *a) {
	lenT = strlen(a);
    nextP[lenT][0] = nextP[lenT][1] = lenT;
    ways[lenT] = 0;
	for(int i=lenT-1; i>=0; i--) {
		T[i] = mapo[(int) a[i]];
        nextP[i][0] = nextP[i+1][0];
        nextP[i][1] = nextP[i+1][1];
        if(T[i] == 2)
            continue;
        ways[i] = (ways[nextP[i][0]] + ways[nextP[i][1]] + 1) % mod; ;
        nextP[i][T[i]] = i;
	}
	// for(int i=0; i<lenT; i++) {
    //     printf("%d ", ways[i]);
	// }
    // printf("\n");
}

ll testCase() {
	char tmp[limN];
	scanf("%s", tmp);
	procaS(tmp);
	scanf("%s", tmp);
	procaT(tmp);
	ll ans = (ways[nextP[0][0]] + ways[nextP[0][1]] + 1) % mod;
	for(int i=0, u=0; i<lenT && u < lenS; i++) {
		if(T[i] != 2) continue;
		u++;
		int w = S[lenS - u];
		ans = (ans + ways[nextP[i][1-w]] + 1) % mod;
	}
	return ans;
}

int main() {
	mapo['U'] = 2;
	mapo['L'] = 0;
	mapo['R'] = 1;
	int numC ;
	scanf("%d", &numC);
	for(int i=1; i<=numC; i++)
		printf("Case %d: %d\n", i, testCase());
}
