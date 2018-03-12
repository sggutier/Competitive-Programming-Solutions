#include <bits/stdc++.h>
using namespace std;

int N, CC, s[200005], z[200005], b[200005];

void makePref(const int &N, int *str, int *prev) {
    int i=-1, j=0;
    prev[0] = -1;
    while(j<N) {
        while(i!=-1 && str[i]!=str[j])
            i = prev[i];
        i++, j++;
        prev[j] = i;
    }
}

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;i++)
        scanf("%d", &z[i]);

    s[0] = 1;
    CC = 2;

    for(int i=1;i<N;) {
        if(z[i] == 0) {
            s[i] = CC++; i++;
        } else {
            for(int j=0;j<z[i];j++)
                s[i+j] = s[j];
            i += z[i];
        }
    }

    makePref(N, s, b);

    for(int i=1; i<=N; i++) {
        if(i!=1)
            printf(" ");
        printf("%d", b[i]);
    }
    printf("\n");

    return 0;
}
