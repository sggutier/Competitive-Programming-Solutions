#include <bits/stdc++.h>
using namespace std;
#define ll unsigned int

ll calcAns(ll N, ll L, ll U, ll p) {
    if(p==1U) {
        if( (N&p) )
            return (L & p);
        else
            return (U & p);
    }
    //printf("%2u %2u %2u => %d %d %d => %u\n", N, L, U, (N&p)!=0, (L&p)!=0, (U&p)!=0, p);
    if( (L&p) && (U&p) )
        return calcAns(N, L, U, p>>1) | p;
    else if( !(L&p) && !(U&p) )
        return calcAns(N, L, U, p>>1) ;
    else if( !(N&p) )
        return calcAns(N, p, U, p>>1) | p;
    else
        return calcAns(N, L, p-1, p>>1) ;
}

int main() {
    ll n, l, u;
    while(scanf("%u%u%u", &n, &l, &u)!=EOF)
        printf("%u\n", calcAns(n, l, u, (1U<<31)));
}
