#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second

bool itWorks(vector <par> rocks, int D, int dir=1) {
    int N = rocks.size();
    int pos = dir==1? 0 : N-1;
    //printf("Trying %d (%d):\n" ,D, dir);
    N--;
    do {
        int sig = pos+dir, bo=pos;
        while(true) {
            if(abs(rocks[sig].f - rocks[pos].f) > D)
                break;
            if(rocks[sig].s > 0) {
                bo = sig;
                break;
            }
            if(rocks[sig].s)
                bo = sig;
            sig += dir;
        }
        //printf("At %d, with sig %d (%d)\n", rocks[pos].f, rocks[bo].f, rocks[bo].s);
        if(bo==pos)
            return false;
        rocks[bo].s ++;
        pos = bo;
    } while(pos%N);
    if(dir==1)
        return itWorks(rocks, D, -1);
    return true;
}

void testCase() {
    int N, D;

    scanf("%d%d", &N, &D);
    vector <par> rocks(N+2);
    for(int i=0; i<N; i++) {
        char tmp[15];
        int c;
        scanf("%s", tmp);
        sscanf(tmp+2,"%d ", &c);
        //printf("%c-%d ", tmp[0], c);
        rocks[i] = par(c, tmp[0]=='B'? 1 : -1);
    }
    //printf("\n");
    rocks[N] = par(0, 1);
    rocks[N+1] = par(D, 1);
    sort(rocks.begin(), rocks.end());

    int ini=1, fin=D;
    while(ini<fin) {
        int piv = (ini+fin)/2;

        if(itWorks(rocks, piv))
            fin = piv;
        else
            ini = piv+1;
    }

    printf("%d\n", ini);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
