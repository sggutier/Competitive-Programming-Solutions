#include <bits/stdc++.h>
using namespace std;
const int limC = 24;
const int limS = 31;

int carVal[limC];
bool usd[1<<limC];
bool ganaMem[1<<limC];

bool gana(int msk, int sum) {
    if(usd[msk])
        return ganaMem[msk];
    usd[msk] = true;
    if(sum>=31)
        return ganaMem[msk] = false;
    for(int c=0; c<limC; c++) {
        if((1<<c) & msk)
            continue;
        if(sum + carVal[c] > 31)
            break;
        if(!gana(msk | (1<<c), sum + carVal[c]))
            return ganaMem[msk] = true;
    }
    return ganaMem[msk] = false;
}

void testCase(char *s) {
    int n = strlen(s);
    int sum = 0, msk=0;

    for(int i=0; i<n; i++) {
        int k = s[i] - '0';
        sum += k;
        for(int c=0; c<limC; c++) {
            if(((1<<c) & msk)==0 && carVal[c]==k) {
                msk |= (1<<c);
                break;
            }
        }
    }

    // printf("%d => ", sum);
    // for(int c=0; c<24; c++) {
    //     if((1<<c) & msk)
    //         printf("%d ", carVal[c]);
    // }
    // printf("\n");

    printf("%s %c\n", s, (gana(msk, sum) + n%2)%2? 'A' : 'B');
}

void precarga() {
    for(int i=1; i<=6; i++) {
        for(int k=0; k<4; k++) {
            carVal[(i-1)*4 + k] = i;
        }
    }
}

int main() {
    precarga();
    char S[500];

    while(scanf("%s", S)!=EOF)
        testCase(S);
}
