#include <bits/stdc++.h>
using namespace std;
const int limM = 11;
const int limN = 21;

int N, K;
int M;
list <int> elems[limN];
int rem[limM];
int ado[limM];
int vals[limN];
int ans, aMsk ;

void bruta(int pos=0, int cnt=0, int msk=0, int sum=0) {
    if(pos==N) {
        if(sum>ans) {
            ans = sum;
            aMsk = msk;
        }
        return;
    }
    if(cnt!=K) {
        for(const int &e:elems[pos]) {
            if(rem[e])
                sum -= ado[e];
            rem[e] ++;
        }
        bruta(pos+1, cnt+1, msk | (1<<pos), sum + vals[pos]);
        for(const int &e:elems[pos]) {
            rem[e] --;
            if(rem[e])
                sum += ado[e];
        }
    }
    bruta(pos+1, cnt, msk, sum);
}

void testCase() {
    for(int i=0; i<N; i++) {
        scanf("%d", &vals[i]);
        elems[i].clear();
    }
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        int a ;
        scanf("%d", &rem[i]);
        for(int j=0; j<rem[i]; j++) {
            scanf("%d", &a);
            elems[a-1].push_back(i);
        }
        rem[i] = 0;
        scanf("%d", &ado[i]);
    }

    ans = -1;
    bruta();
    printf("Number of Customers: %d\n", ans);
    printf("Locations recommended:");
    for(int i=0; i<N; i++) {
        if(aMsk & (1<<i))
            printf(" %d", i+1);
    }
    printf("\n");
}

int main() {
    int tc = 0;
    while(scanf("%d%d", &N, &K)!=EOF && (N || K)) {
        printf("Case Number  %d\n", ++tc);
        testCase();
        printf("\n");
    }
}
