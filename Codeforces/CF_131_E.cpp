#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii, int> piii;
#define f first
#define s second
const int limN = 1e5 + 5;

map < int, pii > minRen, minCol, minDiaL, minDiaR;
map < int, pii > maxRen, maxCol, maxDiaL, maxDiaR;

void mete(const int s, const pii nov, map <int, pii > & mino, map <int, pii> &maxo) {
    auto itA = mino.find(s);
    if(itA == mino.end())
        mino[s] = nov;
    else
        itA->s = min(itA->s, nov);
    itA = maxo.find(s);
    if(itA == maxo.end())
        maxo[s] = nov;
    else
        itA->s = max(itA->s, nov);
}

int cntBord(const int s, const pii nov, map <int, pii > & mino, map <int, pii> &maxo) {
    int w = 0;
    if(mino[s] == nov)
        w ++;
    if(maxo[s] == nov)
        w ++;
    return 2-w;
}

int ansCnt[9];

int main() {
    int N, Q;
    pii qs[limN];
    scanf("%d%d", &N, &Q);
    
    for(int i=0; i<Q; i++) {
        scanf("%d%d", &qs[i].f, &qs[i].s);
        mete(qs[i].f, qs[i], minRen, maxRen);
        mete(qs[i].s, qs[i], minCol, maxCol);
        mete(qs[i].f + qs[i].s, qs[i], minDiaL, maxDiaL);
        mete(qs[i].f - qs[i].s, qs[i], minDiaR, maxDiaR);
    }

    for(int i=0; i<Q; i++) {
        int s = 
        cntBord(qs[i].f, qs[i], minRen, maxRen)
        + cntBord(qs[i].s, qs[i], minCol, maxCol)
        + cntBord(qs[i].f + qs[i].s, qs[i], minDiaL, maxDiaL)
        + cntBord(qs[i].f - qs[i].s, qs[i], minDiaR, maxDiaR);
        ansCnt[s] ++;
    }

    for(int i=0; i<=8; i++)
        printf("%d ", ansCnt[i]);
    printf("\n");
}
