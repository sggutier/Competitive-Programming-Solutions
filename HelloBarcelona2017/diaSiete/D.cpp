#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

char str[limN];
int Z[limN];

void makeZ(const int &N, char *s, int *z) {
    int l=0, r=0;
    for(int i=1; i<N; i++) {
        if(r>=i)
            z[i] = min(z[i-l], r-i+1);
        while(z[i] + i <N && s[z[i]] == s[z[i] + i])
            z[i]++;
        if(i + z[i] -1 > r)
            l = i, r = i + z[i]-1;
    }
}

int main() {
    int N ;

    //gets(str);
    scanf("%s", str);
    N = strlen(str);
    makeZ(N, str, Z);
    
    for(int i=0; i<N; i++) {
        if(i!=0)
            printf(" ");
        printf("%d", Z[i]);
    }
    printf("\n");
}
