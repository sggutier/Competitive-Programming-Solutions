#include <stdio.h>
const int B = 16;
const int limB = 1<<16;

int N, NB;
int prohb[16];
int ans = 0;

void bruta(int rw, int ld, int rd, int *pro) {
    if(rw==NB) {
        ans ++;
        return;
    }
    int pos = NB & (~(rw | ld | rd | *pro));
    while(pos) {
        int p = pos & -pos;
        pos -= p;
        bruta(rw | p, (ld | p) << 1, (rd | p) >> 1, pro+1);
    }
}

void testCase() {
    int i, j;
    ans = 0;
    
    NB = (1<<N)-1;
    for(i=0; i<N; i++) {
        prohb[i] = 0;
        for(j=0; j<N; j++) {
            if(getchar()=='*')
                prohb[i] |= (1<<j);
        }
        getchar();
    }

    bruta(0, 0, 0, prohb);

    printf("%d\n",ans);
}

int main() {
    char a, b;
    int tc = 0;
    while((a=getchar())!=EOF && a!='0') {
        b = getchar();
        printf("Case %d: ", ++tc);
        if(b!='\n') {
            N = 10 + b - '0';
            b = getchar();
        }
        else
            N = a - '0';
        testCase();
    }
}
