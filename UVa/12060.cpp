#include <bits/stdc++.h>
using namespace std;

int digCnt(int n) {
    n = abs(n);
    int ans = 0;
    while(n) {
        n /= 10;
        ans ++;
    }
    return ans;
}

void testCase(int N) {
    int sum = 0;
    for(int i=0; i<N; i++) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
    }
    int d = __gcd(abs(sum), abs(N));
    sum /= d;
    N /= d;
    int a = sum/N;
    sum = sum%N;
    if(abs(a)>=1) {
        sum = abs(sum);
        if(sum==0) {
            if(a<0)
                printf("- ");
            printf("%d\n", abs(a));
        }
        else {
            int digs = digCnt(a) + (a<0? 2 : 0);
            int fr = max(digCnt(sum), digCnt(N));
            char ptStr[10];
            sprintf(ptStr, "%%%dd\n", fr);
            //printf("%s\n", ptStr);

            for(int i=0; i<digs; i++)
                printf(" ");
            printf(ptStr, sum);
            if(a<0)
                printf("- ");
            printf("%d", abs(a));
            for(int i=0; i<fr; i++)
                printf("-");
            printf("\n");
            for(int i=0; i<digs; i++)
                printf(" ");
            printf(ptStr, N);
        }
    }
    else {
        if(sum==0) {
            printf("0\n");            
        }
        else {
            int digs = sum>0? 0 : 2;
            sum = abs(sum);
            int fr = max(digCnt(sum), digCnt(N));
            char ptStr[10];
            sprintf(ptStr, "%%%dd\n", fr);
            //printf("%s\n", ptStr);

            for(int i=0; i<digs; i++)
                printf(" ");
            printf(ptStr, sum);
            if(digs==2)
                printf("- ");
            for(int i=0; i<fr; i++)
                printf("-");
            printf("\n");
            for(int i=0; i<digs; i++)
                printf(" ");
            printf(ptStr, N);
        }
    }
}
    
int main() {
    int n;
    for(int tc=1; scanf("%d", &n)!=EOF && n; tc++) {
        printf("Case %d:\n", tc);
        testCase(n);
    }
}
