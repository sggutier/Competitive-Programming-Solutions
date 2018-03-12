#include <bits/stdc++.h>
using namespace std;
const int limN = 505;
const int inf = 1e9;

int N ;
vector <int> adj[limN];
map <string, int> dico;
string strs[limN];

int minCic(int ini, bool printa=false) {
    vector <int> minP(N);
    vector <int> ant(N, -1);
    queue <int> Q;
    Q.push(ini);
    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
//        printf("%s %d %d\n", strs[pos].c_str(), minP[pos], ant[pos]);
        for(const int &sig:adj[pos]) {
            if(ant[sig]!=-1) continue;
            ant[sig] = pos;
            minP[sig] = minP[pos]+1;
            Q.push(sig);
        }
    }
//    printf("concl => %d %d\n", ant[ini], minP[ini]);

    if(!printa)
        return ant[ini]!=-1? minP[ini] : inf;

    stack <int> cic;
    for(int i=0, p=ini; i<minP[ini]; i++, p=ant[p]) {
        cic.push(p);
    }
    for(int i=0; i<minP[ini]; i++) {
        int p = cic.top(); cic.pop();
        if(i)
            printf(" ");
        printf("%s", strs[p].c_str());
    }
    printf("\n");

    return 0;
}

int main() {
    pair<int,int> ans(inf, 0);
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        char tmp[20];
        scanf("%s", tmp);
        strs[i] = tmp;
        dico[strs[i]] = i;
    }
    for(int i=0; i<N; i++) {
        char tmp[20];
        int lins;
        scanf("%s %d", tmp, &lins);
        int p = dico[tmp];
        for(int j=0; j<lins; j++) {
            scanf("%s", tmp);
            while(scanf("%s", tmp)) {
                string s = tmp;
                bool fino = true;
                if(s[s.size()-1] == ',') {
                    fino = false;
                    s = s.substr(0, s.size()-1);
                }
                adj[p].push_back(dico[s]);
                if(fino)
                    break;
            }
        }
    }

//    printf("El grafo es\n");
//    for(int i=0; i<N; i++) {
//        printf("%s => ", strs[i].c_str());
//        for(const int &sig:adj[i])
//            printf("%s ", strs[sig].c_str());
//        printf("\n");
//    }

    for(int i=0; i<N; i++)
        ans = min(ans, {minCic(i), i});
//    printf("La anso es %d %d\n", ans.first, ans.second);

    if(ans.first == inf)
        printf("SHIP IT\n");
    else
        minCic(ans.second, true);
}
