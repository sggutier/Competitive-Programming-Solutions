#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int K;
    int A[6], B[6], msks[6], prods[6];
    char str[10];
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));

    scanf("%d", &K);
    for(int i=0; i<6; i++) {
        scanf("%s", str);
        for(int j=0; j<5; j++)
            A[j] |= (1<<(str[j]-'A'));
    }
    for(int i=0; i<6; i++) {
        scanf("%s", str);
        for(int j=0; j<5; j++)
            B[j] |= (1<<(str[j]-'A'));
    }

    prods[5] = 1;
    for(int i=4; i>=0; i--) {
        msks[i] = A[i] & B[i];
        prods[i] = 0;
        for(int b=0; b<26; b++) {
            if((1<<b) & msks[i]) {
                prods[i] ++;
            }
        }
        prods[i] *= prods[i+1];
    }

    K --;
    if(K >= prods[0]) {
        printf("NO\n");
        return;
    }

    for(int i=0; i<5; i++) {
        int d = K/prods[i+1];
        K %= prods[i+1];
        for(int b=0; b<26; b++) {
            if((1<<b) & msks[i])
                d--;
            if(d==-1) {
                printf("%c", b+'A');
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
