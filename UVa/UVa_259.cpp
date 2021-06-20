#include <bits/stdc++.h>
using namespace std;
const int limN = 10;
const int limB = (1<<limN);

int bitCnt[limB];

int compCnt ;
bool completableMem[limN + 1][limB];
int sigPaso[limN+1][limB];
vector <char> nombres;
vector <int> disp, req;

bool completable(int pos, int msk) {
    if(pos==compCnt)
        return true ;
    if(sigPaso[pos][msk])
        return completableMem[pos][msk];
    sigPaso[pos][msk] = -1;
    // printf("pos = %d, %d %d\n", pos, disp[pos], req[pos]);
    for(int b=(1<<limN)-1; b>=0; b--) {
        // printf("\t%d -> %d %d %d\n", b, msk&b, disp[pos] &b, bitCnt[b]);
        if((msk & b) || (disp[pos] & b)!=b || bitCnt[b]!=req[pos] || !completable(pos+1, msk | b))
            continue ;
        sigPaso[pos][msk] = b;
        // printf("%d %d -> good %d\n", pos, msk, b);
        return completableMem[pos][msk] = true ;
    }
    // printf("%d %d -> bad\n", pos, msk);
    return completableMem[pos][msk] = false;
}

void testCase(char *linea, size_t &tmpR) {
    int len ;
    char A[500], B[500];
    nombres = vector<char>();
    disp = vector<int>();
    req = vector<int>();
    do {
        sscanf(linea, "%s%s", A, B);
        nombres.push_back(A[0]);
        req.push_back(A[1]-'0');
        int msk = 0;
        for(int i=0; B[i]!=';'; i++)
            msk |= (1<<(B[i]-'0'));
        disp.push_back(msk);
    } while ((len = getline(&linea, &tmpR, stdin)) > 1) ;

    // for(int i=0; i<(int) nombres.size(); i++) {
    //     printf("%c %d -> ", nombres[i], req[i]);
    //     for(int j=0; j<10; j++)
    //         if((1<<j) & disp[i])
    //             printf("%d ", j);
    //     printf("\n");
    // }

    compCnt = nombres.size();
    memset(sigPaso, 0, sizeof(sigPaso));
    if(!completable(0, 0)) {
        printf("!\n");
        return;
    }
    char ans[15] = "__________";
    for(int i=0, msk=0; i<compCnt; i++) {
        int sig = sigPaso[i][msk];
        for(int j=0; j<10; j++)
            if((1<<j) & sig)
                ans[j] = nombres[i];
        msk |= sig;
    }
    printf("%s\n", ans);
}

int main() {
    int len ;
    char *linea = NULL;
    size_t tmpR = 0;

    for(int b=0; b<limB; b++){
        for(int i=0; i<limN; i++)
            if((1<<i) & b)
                bitCnt[b] ++;
    }

    while ((len = getline(&linea, &tmpR, stdin)) != -1) {
        // printf("Retrieved line of length %d:\n", len);
        testCase(linea, tmpR);
    }
    
    return 0;
}
