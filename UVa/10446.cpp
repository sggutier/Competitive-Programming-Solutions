#include <bits/stdc++.h>
using namespace std;
const int limN = 61;
const int limB = 60;

unsigned long long calls[limB+1][limN+1];

void precarga(int back, unsigned long long *ans) {
    ans[0] = ans[1] = 1;
    for(int i=2; i<=limN; i++) {
        ans[i] = 1;
        for(int b=1; b<=back; b++) {
            if(i-b<=1)
                ans[i] ++;
            else
                ans[i] += ans[i-b];
        }
    }
}

int main() {
    for(int i=1; i<=limB; i++)
        precarga(i, calls[i]);
    int a, b;
    int tc=0;
    while(scanf("%d%d", &a, &b)!=EOF && a<=60) {
        printf("Case %d: %llu\n", ++tc, (b<1 || a<=1)? 1ULL : calls[b][a]);
    }
}
