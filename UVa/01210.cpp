#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e4 + 5;

int ways[MAX_N] ;
bool comp[MAX_N];
int primCnt = 1;
int consSums[MAX_N];

void precarga(int N = MAX_N) {
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = true;
    for(int i=2; i<N; i++) {
        if(comp[i])
            continue;
        consSums[primCnt] = consSums[primCnt-1] + i;
        primCnt++;
    }
    for(int i=0; i<primCnt; i++)
        for(int j=i+1; j<primCnt; j++)
            if(consSums[j] - consSums[i] < N)
                ways[consSums[j] - consSums[i]]++;
}

int main() {
    precarga();
    int n;
    while(scanf("%d", &n)!=EOF && n)
        printf("%d\n", ways[n]);
}
