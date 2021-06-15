#include <bits/stdc++.h>
using namespace std;
const int LIM_A = 32000;

int mexs[] = {1, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
bool usd[LIM_A];

int main() {
    int ans = 0;
    int N ;
    scanf("%d", &N);
    int rem = N ;
    if(N == 1) {
        printf("Vasya\n");
        return 0 ;
    }
    int i;
    for(i=2; i*i <= N; i++) {
        if(usd[i]) continue;
        int cnt = 0;
        long long p;
        for(p = i; p <= N; p *= i, cnt++) {
            if(p < LIM_A)
                usd[p] = true;
        }
        rem -= cnt;
        // printf("%d => %d %lld\n", i, cnt, p);
        ans ^= mexs[cnt];
    }
    ans ^= rem % 2;
    printf("%s\n", ans? "Vasya" : "Petya");
}
