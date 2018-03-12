#include <bits/stdc++.h>
using namespace std;
const int limN = 205;

int letCnt;
int cng[limN];
int anto[limN];

void mueve(int leno, char *str) {
    vector <char> usd(letCnt);
    char ans[letCnt];
    for(int i=0; i<letCnt; i++) {
        if(usd[i])
            continue;
        int clen = 0, pos=i;
        // printf("[");
        do {
            usd[pos] = 1;
            anto[clen++] = pos;
            pos = cng[pos];
            // printf("%d ", pos);
        } while(!usd[pos]);
        // printf("] ");
        int ruu = leno%clen;
        // printf("%d (%d) => %d %d\n", i, cng[i], leno, ruu);
        // do {
        //     // int sig = pos;
        //     // for(int w=0; w<ruu; w++) {
        //     //     sig = cng[sig];
        //     // }
        //     // ans[sig] = str[pos];
        //     ans[
        //     pos = cng[pos];
        // } while(pos!=i) ;
        for(int w=0; w<clen; w++) {
            ans[anto[(w+ruu)%clen]] = str[anto[w]];
        }
    }
    for(int i=0; i<letCnt; i++)
        str[i] = ans[i];
}

void testCase() {
    char str[letCnt+7];
    for(int i=0; i<letCnt; i++) {
        scanf("%d", &cng[i]);
        cng[i] --;
    }
    int leno ;
    while(scanf("%d", &leno)!=EOF && leno) {
        scanf("%c", &str[0]);
        for(int i=0; true; i++) {
            scanf("%c", &str[i]);
            if(str[i]=='\n') {
                // cout << i << endl;
                for(int j=i; j<=letCnt; j++)
                    str[j] = ' ';
                str[letCnt] = 0;
                // printf("[%s]\n", str);
                break;
            }
        }
        mueve(leno, str);
        printf("%s\n", str);
    }
    printf("\n");
}

int main() {
    while(scanf("%d", &letCnt)!=EOF && letCnt)
        testCase();
}
