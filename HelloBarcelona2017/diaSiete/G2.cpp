#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int str[limN];
int pref[limN];

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

int main(){
    int N, K;

    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &str[i]);
        str[2*N-i] = str[i];
    }
    str[N] = -1e9;

    makeZ(2*N+1, str, pref);

    int cnt = 0;
    for(int i=0; i<N; i++) {
        if(pref[i+N+1] && pref[i+N+1]%2==0) {
            int t = pref[i+N+1]/2;
            if(2*t >= N-t) {
                if(cnt++)
                    printf(" ");
                int t = pref[i+N+1]/2;
                printf("%d", N-t);
            }
        }
    }

    if(cnt++)
        printf(" ");
    printf("%d", N);
    printf("\n");
    return 0;
}
