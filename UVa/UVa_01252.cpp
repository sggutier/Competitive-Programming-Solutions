#include <bits/stdc++.h>
using namespace std;
const int limN = 11;
const int limB = (1<<limN);
const int limK = 128;
const __int128 uno = 1;

int N, NB, K;
__int128 numBs[limN][2];
int minQMemo[limB][limB];
bool usdMemo[limB][limB];

void printBin(__int128 msk, int N = N) {
    int cnt = 0;
    for(int i=0; i<N; i++) {
        if((uno<<i) & msk) {
            if(cnt++)
                printf(", ");
            printf("%d", i);
        }
    }
    printf("\n");
}

void printSta(int avil=NB-1, int dec=0, __int128 nums=uno<<K, int pos=0, int ans = 0) {
    avil = NB-1-avil;
    printf("Stat: %d %d\n", pos, ans);
    // printBin(avil & (NB-1-dec));
    // printBin(avil & dec);
    printBin(nums, K);    
}

int minQ(int avil=NB-1, int dec=0, __int128 nums=(uno<<K) - 1) {
    if(usdMemo[avil][dec])
        return minQMemo[avil][dec];
    usdMemo[avil][dec] = 1;
    //if(orgs.count(nums)==1) {
    if(nums == (nums & -nums)) {
        return minQMemo[avil][dec] = 0;
    }
    if(nums==0 || avil==0) {
        //printSta(avil, dec, nums, pos, -1);
        return minQMemo[avil][dec] = -1;
    }
    
    int ans = N;
    //int pos2 = pos;
    for(int pos=0; pos<N; pos++) {
        if(avil & (1<<pos))
        ans = min(ans, 1+max(minQ(avil-(1<<pos), dec+(1<<pos), nums&numBs[pos][1]),
                             minQ(avil-(1<<pos), dec         , nums&numBs[pos][0])));
    }

    // printf("[%d %d] %d\n", avil, dec, (int) nums);
    // //printSta(avil, dec, nums, pos2, ans);
    // printf("From V:\n");
    // for(pos=pos2; pos<N; pos++) {
    //     //if(avil & (1<<pos))
    //     printf("\t [%d %d] %d (%d) ", avil-(1<<pos), dec+(1<<pos), (int) (nums&numBs[pos][1]), minQ(avil-(1<<pos), dec+(1<<pos), nums&numBs[pos][1], pos+1));
    //     printf("\t [%d %d] %d (%d)\n", avil-(1<<pos), dec, (int) (nums&numBs[pos][0]), minQ(avil-(1<<pos), dec, nums&numBs[pos][0], pos+1));
                             
    // }
    return minQMemo[avil][dec] = ans;
}

void testCase() {
    memset(usdMemo, 0, sizeof(usdMemo));
    //orgs.clear();
    
    int ks[limK];
    char str[limK];
    NB = 1<<N;

    for(int i=0; i<K; i++) {
        scanf("%s", str);
        int sum = 0;
        for(int j=0; j<N; j++)
            if(str[j]=='1')
                sum += 1<<j;
        ks[i] = sum;
        // printf("NumK (%d) => ", i);
        // printBin(sum);
        //orgs.insert(uno<<i);
    }

    for(int i=0; i<N; i++) {
        __int128 sumA = 0, sumB = 0;
        for(int j=0; j<K; j++)
            if((1<<i) & ks[j])
                sumA += uno<<j;
            else
                sumB += uno<<j;
        numBs[i][0] = sumB;
        numBs[i][1] = sumA;
    }

    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<2; j++) {
    //         printf("%s %d => ", j? "Si" : "No", i);
    //         printBin(numBs[i][j], K);
    //     }
    // }

    printf("%d\n", minQ());
}

int main() {
    while(scanf("%d%d", &N, &K)!=EOF && (N || K))
        testCase();
    
    return 0;
}
