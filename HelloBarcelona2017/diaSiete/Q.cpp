#include <bits/stdc++.h>
using namespace std;
const int limN = 8005;

char str[limN];
int matZ[limN][limN];

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
    scanf("%s", str);
    int L = strlen(str);
    long long ans = 0;

    //makeZ(L, str, Z);

    for(int i=0; i<L; i++) {
        //makeZ(L-i, str+i, Z);
        int n = L-i;
        //ans += (n*(n+1))/2;
        makeZ(n, str+i, i + matZ[i]);
        // for(int j=0; j<i; j++)
        //     printf("# ");
        for(int j=0; j<L; j++)
            printf("%d ", matZ[i][j]);
        printf("\n");
    }

    for(int i=0; i<L; i++) {
        int n = L-i;
        long long maxW = 0;
        ans += (n*(n+1))/2;
        for(int j=0; j<L; j++) {
            maxW = max(maxW, (long long) matZ[j][i]);
        }
        ans -= (maxW*(maxW+1))/2;
    }

    printf("%lld\n", ans);
}
