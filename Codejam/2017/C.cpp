#include <bits/stdc++.h>
using namespace std;

void testCase(long long n, long long k) {
    map <long long, long long> cnt ;
    cnt[-n] = 1 ;
    while(true) {
        map <long long, long long>::iterator it = cnt.begin();
        long long t = -it->first, c = it->second;
        long long der = t/2LL, izq = t-1-der ;
        // printf("%lld %lld -> %lld %lld\n", t, c, der, izq);
        cnt.erase(it);
        if(k<=c) {
            printf("%lld %lld\n", der, izq);
            return ;
        }
        k -= c ;
        cnt[-der] += c ;
        cnt[-izq] += c ;
    }
}

int main() {
    int tc ;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        long long n, k ;
        scanf("%lld%lld", &n, &k);
        printf("Case #%d: ", i);
        testCase(n, k);
    }
    
    return 0;
}
