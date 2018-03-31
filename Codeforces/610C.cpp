#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 6;

char str[limN];

int main() {
    int N ;
    scanf("%d", &N);
    N = (1<<N);
    for(int i=0; i<N; i++)
        printf("+");
    printf("\n");
    for(int i=0; i+1<N; i++) {
        str[i] = 2*(i+1) < (N-1)? '+' : '*';
    }
    for(int i=1; i<N; i++) {
        printf("+");
        for(int j=1; j<N; j++) {
            printf("%c", str[(j-1+i) % (N-1)]);
        }
        printf("\n");
    }
}
