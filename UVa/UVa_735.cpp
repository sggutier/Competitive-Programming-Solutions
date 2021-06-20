#include <bits/stdc++.h>
using namespace std;
const int limS = 60;

bool divo[limS+1];

void testCase(int N) {
    int aX = 0, aY = 0;
    for(int i=0; i<=limS; i++) {
        if(!divo[i])
            continue;
        for(int j=i; j<=limS; j++) {
            if(!divo[j])
                continue;
            for(int k=j; k<=limS; k++) {
                if(!divo[k])
                    continue;
                if(i + j + k !=N)
                    continue;
                aX ++ ;
                if(i==j && j==k)
                    aY ++ ;
                else if(i==j || j==k)
                    aY += 3;
                else
                    aY += 6;
            }
        }
    }
    if(!aX)
        printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", N);
    else {
        printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", N, aX);
        printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", N, aY);
    }
    printf("**********************************************************************\n");
}

int main() {
    for(int i=20; i>=0; i--) {
        divo[i] = divo[i*2] = divo[i*3] = 1;
    }
    divo[50] = true;
    
    int n;

    while(scanf("%d", &n)!=EOF && n>0)
        testCase(n);
    printf("END OF OUTPUT\n");
}
