#include <bits/stdc++.h>
using namespace std;
const int limN = 110;
const int limP = 1000005;

int pos[limP];
int tele[limN];

void testCase() {
    for(int i=0; i<100; i++)
        tele[i] = i;
    for(int i=100; i<limN; i++)
        tele[i] = 100;
    
    int N, P, Q ;
    bool fini = false;

    scanf("%d%d%d", &N, &P, &Q);
    for(int i=0; i<P; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        tele[a] = b;
    }
    for(int i=0; i<N; i++)
        pos[i] = 1;
    for(int i=0; i<Q; i++) {
        int d ;
        scanf("%d", &d);
        if(fini)
            continue;
        pos[i%N] = tele[pos[i%N]+d];
        if(pos[i%N]==100)
            fini = true;
    }

    for(int i=0; i<N; i++) {
        printf("Position of player %d is %d.\n", i+1, pos[i]);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
