#include <bits/stdc++.h>
using namespace std;
const int limN = 2e6 ;

vector <string> dico, du;
map <string, int> revPals, revUsrs;
int reps[limN];
set <int> usd[limN];
char tmp[limN];
vector < pair<int, string> > ans;

typedef char* chp;

bool leePalb(char *ans, chp &src) {
	while(*src == ' ')
		src ++;
	if(*src == '\n' || *src == 0)
		return 0;
	while(*src != ' ' && *src != '\n') {
		*ans = *src;
		ans++, src++;
	}
	*ans = 0;
	return 1;
}

int getOrd(string S, map <string, int> &rev, vector<string> &d) {
	auto it = rev.find(S);
	if(it == rev.end()) {
		rev[S] = (int) d.size();
		d.push_back(S);
	}
	return rev[S];
}

void procLin() {
	fgets(tmp, limN, stdin);
	char palb[50];
	//~ int N ;
	char *s = tmp;
	
	
	leePalb(palb, s);
	int U = getOrd(palb, revUsrs, du);
	//~ printf("%s => ", palb);
	while(leePalb(palb, s)) {
		int w = getOrd(palb, revPals, dico);
		usd[w].insert(U);
		reps[w] ++;
		//~ printf("[%s] (%d) ", palb, w);
	}
	//~ printf("\n");
}

int main() {
	int lins ;
	fgets(tmp, limN, stdin);
	sscanf(tmp, "%d", &lins);
	while(lins--) {
		procLin();
	}
	//~ return 0;
	int U = revUsrs.size();
	int W = dico.size();
	for(int i=0; i<W; i++) {
		//~ printf("%s => %d %d\n", dico[i].c_str(), (int) usd[i].size(), reps[i]);
		if((int) usd[i].size() == U)
			ans.push_back({-reps[i], dico[i]});
	}
	sort(ans.begin(), ans.end());
	for(auto &a : ans)
		printf("%s\n", a.second.c_str());
	if(ans.empty())
		printf("ALL CLEAR\n");
}

