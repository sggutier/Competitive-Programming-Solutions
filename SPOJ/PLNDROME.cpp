#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5;

void testCase() {
    int N ;
    int difCnt = 0;
    char s[LIM_N];
    int Q ;

    scanf("%d%s", &N, s);
    for(int i=0; 2*i < N; i++) {
        if(s[i] != s[N-1-i]) {
            difCnt ++;
        }
    }
    scanf("%d", &Q);
    for(int i=0; i < Q; i++) {
        char c ;
        int k ;
        scanf("\n%d %c", &k, &c);
        k--;
        difCnt -= s[k] != s[N-1-k]? 1 : 0;
        s[k] = c;
        difCnt += s[k] != s[N-1-k]? 1 : 0;
        printf("%s\n", difCnt? "NO" : "YES");
    }
}

int main() {
    int T;

    scanf("%d", &T);
    for(int i=0; i < T; i++) {
        printf("Case %d:\n", i+1);
        testCase();
    }
}
