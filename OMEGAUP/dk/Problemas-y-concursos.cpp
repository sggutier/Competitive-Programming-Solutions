#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

int N;
int ultN[limN];
bool posb[limN];

int main() {
    int Q ;
    scanf("%d%d", &N, &Q);
    posb[0] = true;
    for(int i=1, a; i<=N; i++) {
        scanf("%d", &a);
        for(int j=limN-1; j>=a; j--)
            if(posb[j-a])
                posb[j] = true;
    }
    for(int i=0, u=0; i<limN; i++) {
        if(posb[i])
            u = i;
        ultN[i] = u;
    }
    while(Q--) {
        int a ;
        scanf("%d", &a);
        printf("%d\n", ultN[a]);
    }
}
