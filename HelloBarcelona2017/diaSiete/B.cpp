#include <bits/stdc++.h>
using namespace std;

int N, b[200005], s[200005], z[200005];

void makeZ(const int &N, int *s, int *z) {
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
    scanf("%d", &N);

    for(int i = 0; i<N; i++)
        scanf("%d", &b[i]);

    int cc = 1;

    for(int i = 0; i<N; i++)
        s[i] = (b[i] > 0) ? s[b[i] - 1] : cc++;

    makeZ(N, s, z);

    for(int i=0; i<N; i++) {
        if(i!=0)
            printf(" ");
        printf("%d", z[i]);
    }
    printf("\n");

    return 0;
}
