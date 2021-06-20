#include <bits/stdc++.h>
using namespace std;

int primCnt = 0;
int primos[100];
bool comp[100];

void criba(int n) {
    for(int i=2; i*i<n; i++)
        if(!comp[i])
            for(int j=i*i; j<n; j+=i)
                comp[j] = true;
    for(int i=2; i<n; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}

void testCase(int n) {
    vector <int> ans(primCnt);

    for(int i=1; i<=n; i++) {
        int k = i;
        for(int j=0; j<primCnt; j++) {
            while(k%primos[j]==0) {
                k /= primos[j];
                ans[j] ++ ;
            }
        }
    }

    printf("%3d! =", n);
    for(int i=0, cnt=0; i<primCnt; i++) {
        if(!ans[i])
            continue;
        if(cnt && cnt%15==0)
            printf("\n      ");
            // printf("\n\t");
        printf(" %2d", ans[i]);
        cnt ++;
    }
    printf("\n");
}

int main() {
    criba(100);
    int n;

    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
    
    return 0;
}
