#include <bits/stdc++.h>
using namespace std;
const int limN = 505;
const int inf = (1<<29);

void testCase(int E) {
    map <string, int> ids;
    string noms[limN];
    int minP[limN][limN];
    int cnt = 0;
    int ansCnt = 0;
    int ax, ay, bx, by;

    for(int i=0; i<limN; i++) {
        for(int j=0; j<limN; j++)
            minP[i][j] = inf;
        minP[i][i] = 0;
    }

    while(E--) {
        int K;
        scanf("%d", &K);
        if(!K)
            continue;
        int prev, act;
        char tmp[limN];
        K--;
        scanf("%s", tmp);
        auto it = ids.find(tmp);
        if(it==ids.end()) {
            noms[cnt] = tmp;
            ids[tmp] = cnt++;
        }
        prev = ids[tmp];
        while(K--) {
            scanf("%s", tmp);
            it = ids.find(tmp);
            if(it==ids.end()) {
                noms[cnt] = tmp;
                ids[tmp] = cnt++;
            }
            act = ids[tmp];
            minP[prev][act] = 1;
            prev = act;
        }
    }

    scanf("%d", &E);
    while(E--) {
        int K = 2;
        int prev, act;
        char tmp[limN];
        K--;
        scanf("%s", tmp);
        auto it = ids.find(tmp);
        if(it==ids.end()) {
            noms[cnt] = tmp;
            ids[tmp] = cnt++;
        }
        prev = ids[tmp];
        noms[prev] = tmp;
        while(K--) {
            scanf("%s", tmp);
            it = ids.find(tmp);
            if(it==ids.end()) {
                noms[cnt] = tmp;
                ids[tmp] = cnt++;
            }
            act = ids[tmp];
            minP[prev][act] = 1;
            prev = act;
        }
    }

    for(int k=0; k<cnt; k++)
        for(int i=0; i<cnt; i++)
            for(int j=0; j<cnt; j++)
                minP[i][j] = min(minP[i][j], minP[i][k] + minP[k][j]);

    for(int i=0; i<cnt; i++) {
        for(int j=i+1; j<cnt; j++) {
            if(minP[i][j]!=inf || minP[j][i]!=inf)
                continue;
            ansCnt ++;
            if(ansCnt==1)
                ax = i, ay = j;
            if(ansCnt==2)
                bx = i, by = j;
        }
    }

    if(ansCnt==0)
        printf("no concurrent events.\n");
    else if(ansCnt==1)
        printf("%d concurrent events:\n(%s,%s) \n", ansCnt, noms[ax].c_str(), noms[ay].c_str());
    else
        printf("%d concurrent events:\n(%s,%s) (%s,%s) \n", ansCnt, noms[ax].c_str(), noms[ay].c_str(), noms[bx].c_str(), noms[by].c_str());
}

int main() {
    int n;
    int tc=0;
    while(scanf("%d", &n)!=EOF && n) {
        printf("Case %d, ", ++tc);
        testCase(n);
    }
}
