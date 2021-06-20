#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
const int limN = 1e3 + 5;



void testCase(int topCnt) {
    int topDurs[limN];
    par arr[limN];
    int L, C;
    scanf("%d%d", &L, &C);
    for(int i=1; i<=topCnt; i++) {
        scanf("%d", &topDurs[i]);
    }

    for(int i=1; i<=topCnt; i++) {
        par ans = par((1<<30), 0);
        for(int j=i-1, sum=topDurs[i]; j>=0 && sum<=L; j--) {
            int dif = L-sum;
            if(dif==0)
                ans = min(ans, par(arr[j].f+1, arr[j].s));
            else if(dif<=10)
                ans = min(ans, par(arr[j].f+1, arr[j].s - C));
            else {
                dif -= 10;
                ans = min(ans, par(arr[j].f+1, arr[j].s + dif*dif));
            }
            sum += topDurs[j];
        }
        arr[i] = ans;
    }
    printf("Minimum number of lectures: %d\n", arr[topCnt].f);
    printf("Total dissatisfaction index: %d\n", arr[topCnt].s);
}

int main() {
    int n;
    int tc = 0;

    while(scanf("%d", &n)!=EOF && n) {
        if(tc++)
            printf("\n");
        printf("Case %d:\n", tc);
        testCase(n);
    }
    
    return 0;
}
