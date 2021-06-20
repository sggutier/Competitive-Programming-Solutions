#include <bits/stdc++.h>
using namespace std;
const int limN = 40;

bitset<limN> comp;

void criba(int N = limN) {
    comp[0] = comp[1] = true;
    for(int i=2; i*i<N; i++)
        if(!comp[i])
            for(int j=i*i; j<N; j+=i)
                comp[j] = true;
}

int main() {
    criba();
    int n ;
    while(scanf("%d", &n)!=EOF && n) {
        if(!comp[n]) {
            if(n!=11 && n!=23 && n!=29)
                printf("Perfect: %lld!\n", (1LL<<(n-1)) * ((1LL<<n)-1));
            else
                printf("Given number is prime. But, NO perfect number is available.\n");
        }
        else
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }
}
