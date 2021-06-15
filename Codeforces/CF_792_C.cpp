#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N ;
    int erCnt = 0;
    char str[limN];
    int sm = 0;
    int dosCnt = 0;
    int unoCnt = 0;

    scanf("%s", str);
    N = strlen(str);
    for(int i=0; i<N; i++) {
        sm += str[i]-'0';
        if((str[i]-'0')%3 == 2)
            dosCnt ++;
        else if((str[i]-'0')%3 == 1)
            unoCnt ++;
    }
    sm %= 3;

    if(sm == 2 && dosCnt == 1 && (str[0]-'0')%3 == 2 && str[1] == '0' && str[2] == '0' && N > 2 && unoCnt >= 2) {
        for(int i=N-1; i>=0 && sm; i--) {
            if(str[i] && (str[i]-'0') % 3 == 1 ) {
                str[i] = 0;
                sm --;
                erCnt ++;
            }
        }
    }
    else if(sm == 1 && unoCnt == 1 && (str[0]-'0')%3 == 1 && str[1] == '0' && str[2] == '0' && N > 2 && dosCnt >= 2) {
        for(int i=N-1; i>=0 && sm; i--) {
            if(str[i] && (str[i]-'0') % 3 == 2 ) {
                str[i] = 0;
                sm = (sm + 1) % 3;
                erCnt ++;
            }
        }
    }

    for(int i=N-1; i>=0 && sm; i--) {
        if((str[i]-'0') % 3 == sm) {
            str[i] = 0;
            erCnt ++;
            sm = 0;
            break;
        }
    }

    int w = sm==1? 2 : 1;
    for(int i=N-1; i>=0 && sm; i--) {
        if(str[i] && (str[i]-'0') % 3 == w ) {
            str[i] = 0;
            sm = (sm + 3 - w) % 3;
            erCnt ++;
        }
    }

    if(erCnt == N || sm) {
        printf("-1\n");
        return 0 ;
    }

    bool isZero = true;
    for(int i=0; i<N; i++)
        if(str[i] && str[i] != '0')
            isZero = false;

    if(isZero) {
        printf("0\n");
        return 0 ;
    }

    for(int i=0, fca = 0; i<N; i++) {
        if(str[i] % '0' || (fca>0 && str[i])) {
            printf("%c", str[i]);
            fca ++;
        }
    }
    printf("\n");
}
