#include <bits/stdc++.h>
using namespace std;
const int limN = 10;

int N;
double dst[limN];
double sum[limN], alo[limN];

bool itWorks(double sp) {
    if(sp>60.0)
        return false;
    for(int i=0; i<N; i++)
        if(fmod(dst[i]/sp, sum[i]) > alo[i])
            return false;
    return true;
}

void testCase() {
    for(int i=0; i<N; i++) {
        scanf("%lf", &dst[i]);
        dst[i] *= 3600;
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        sum[i] = a+b+c;
        alo[i] = a+b;
    }
    int ans = 0, fst=30, w=0;
    for(int i=30; i<=61; i++) {
        if(!itWorks(i)) {
            if(w) {
                printf("%c %d", (ans++)? ',' : ':',fst);
                if(i-1!=fst)
                    printf("-%d", i-1);
                w = 0;
            }
            fst = i+1;
        }
        else {
            // printf(" [%d]", i);
            w++;
        }
    }
    if(!ans)
        printf(": No acceptable speeds.");
    printf("\n");
}

int main() {
    int tc=1;

    while(scanf("%d", &N)!=EOF && N != -1) {
        printf("Case %d", tc++);
        testCase();
    }
    
    return 0;
}
