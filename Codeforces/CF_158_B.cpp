#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
    int N ;
    int cnt[] = {0,0,0,0,0} ;
    int res = 0, a ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d", &a ) ;
        cnt[a] ++ ;
    }

    res += cnt[4] ;
    a = min( cnt[1], cnt[3] ) ;
    res += a ;
    cnt[1] -= a ;
    cnt[3] -= a ;
    res += cnt[3] ;
    a = min( cnt[1]/2, cnt[2] ) ;
    res += a ;
    cnt[1] -= a*2 ;
    cnt[2] -= a ;
    res += cnt[2]/2 ;
    res += cnt[2]%2 ;
    a = cnt[2]%2 ;
    cnt[1] = max( 0, cnt[1]-a*2 ) ;
    res += cnt[1]/4 ;
    res += (cnt[1]%4)>0 ;

    printf("%d\n", res ) ;

    return 0 ;
}
