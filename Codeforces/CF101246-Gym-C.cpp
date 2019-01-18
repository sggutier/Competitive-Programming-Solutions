#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii; 

int R, C;
int msks[30];
int W ;

string pnum(int n) {
	string ans = "";
	for(int i=0; i<C; i++)
		ans += (1<<i) & n? "1" : "0";
	return ans;
}

bool posb(int rem, const int pos = 0, const int m = 0) {
	if(rem == 0) {
		int cnt = 0 ;
		for(int i=0; i<R; i++) {
			if( msks[i] ^ (m & msks[i]) )
				cnt ++;
		}
		//~ printf("%d %s => %d\n", W, pnum(m).c_str(), cnt);
		return cnt <= W;
	}
	if(pos == C)
		return false;
	return posb(rem, pos+1, m) || posb(rem-1, pos+1, m | (1<<pos));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &R, &C);
	for(int i=0; i<R; i++) {
		char tmp[30];
		scanf("%s", tmp);
		for(int j=0; j<C; j++)
			msks[i] += (tmp[j]=='*'? 1 : 0) << j;
	}
	
	int ini = 0, fin = min(R, C);
	while(ini < fin) {
		W = (ini+fin) / 2 ;
		if(posb(W))
			fin = W ;
		else
			ini = W+1;
	}
	
	printf("%d\n", ini);
}

