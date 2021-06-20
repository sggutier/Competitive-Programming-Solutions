#include <bits/stdc++.h>
using namespace std;
#define Par pair<int,int>
#define Tri pair<int,Par>
#define Plyr pair<string, Par>
#define f  first
#define s second
#define mp make_pair
const int limN = 10;

int bitCnt[1<<limN];

void precarga(int pos=0, int msk=0, int on=0) {
    if(pos==limN) {
        bitCnt[msk] = on;
        return;
    }
    precarga(pos+1, msk, on);
    precarga(pos+1, msk | (1<<pos), on + 1);
}

void testCase() {
    Plyr players[limN];
    Tri ans = mp(-(1<<30), mp(-(1<<30), 0));
    for(int i=0; i<limN; i++) {
        cin >> players[i].f >> players[i].s.f >> players[i].s.s ;
    }
    sort(players, players+limN);
    int fin = (1<<limN)-1;
    for(int b=0; b<fin; b++) {
        if(bitCnt[b]!=5)
            continue;
        int atckSum = 0, defSum = 0;
        for(int i=0; i<limN; i++) {
            if((1<<i) & b)
                defSum += players[limN-1-i].s.s;
            else
                atckSum += players[limN-1-i].s.f;
        }
        ans = max(ans, mp(atckSum, mp(defSum, -b)));
    }
    int w = -ans.s.s;
    printf("(");
    for(int i=limN-1, b=0; i>=0; i--) {
        if(((1<<i) & w)==0) {
            if(b++)
                printf(", ");
            printf("%s", players[limN-1-i].f.c_str());
        }
    }
    printf(")\n");
    printf("(");
    for(int i=limN-1, b=0; i>=0; i--) {
        if(((1<<i) & w)!=0) {
            if(b++)
                printf(", ");
            printf("%s", players[limN-1-i].f.c_str());
        }
    }
    printf(")\n");
}

int main() {
    precarga();
    int tc;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        printf("Case %d:\n", i+1);
        testCase();
    }
    
    return 0;
}
