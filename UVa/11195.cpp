#include <cstdio>
using namespace std;
const int B = 16;
const int limB = 1<<B;

int N, NB;
int prohb[B];
int ans = 0;

void bruta(int rw=0, int ld=0, int rd=0, int *pro=prohb) {
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
    ans = 0;
    
    char mapa[20];
    NB = (1<<N)-1;
    for(int i=0; i<N; i++) {
        gets(mapa);
        prohb[i] = 0;
        for(int j=0; j<N; j++)
            if(mapa[j]=='*')
                prohb[i] |= (1<<j);
    }

    bruta();

    printf("%d\n",ans);
}

int main() {
    int tc = 0;
    char str[5];
    while(gets(str) && str[0]!='0') {
        printf("Case %d: ", ++tc);
        if(str[1])
            N = 10 + str[1] - '0';
        else
            N = str[0] - '0';
        testCase();
    }
}
