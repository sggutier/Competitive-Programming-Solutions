#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    scanf("%d", &N);
    N = (1<<N);
    for(int i=0; i<N; i++)
        printf("+");
    printf("\n");
    for(int i=0; i+1<N; i++) {
        for(int j=0; j<i; j++)
            printf("*");
        printf("++");
        for(int j=N-2-i; j>0; j--)
            printf("*");
        printf("\n");
    }
}
