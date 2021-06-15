#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 10000

int N=0 ;
long long nums[lim] ;

long long genNum( int W, int K ) {
    long long pot=1LL, res=0LL ;

    for( int i=0; i<K; i++, pot*=10LL ) {
        if( (1<<i) & W )
            res += pot*7 ;
        else
            res += pot*4 ;
    }

    return res ;
}

void genera() {
    nums[N++] = 0LL ;

    for( int j=1; j<=10; j++ ) {
        for( int i=0; i<(1<<j); i++ ) {
            nums[N++] = genNum(i,j) ;
        }
    }
}

long long intersec( long long A, long long B, long long X, long long Y ) {
    return max(  min(Y,B) - max(X,A)+1LL,  0LL  ) ;
}

int main() {
    long long vl, vr, pl, pr, K ;
    long long rA=0LL, rB=0LL ;

    genera() ;

    cin >> vl >> vr >> pl >> pr >> K ;

    for( int i=K; i+1<N; i++ ) {
        rA += intersec( nums[i-K]+1, nums[i-K+1],  vl, vr )  *  intersec( nums[i], nums[i+1]-1,  pl, pr )  ;
        rA += intersec( nums[i-K]+1, nums[i-K+1],  pl, pr )  *  intersec( nums[i], nums[i+1]-1,  vl, vr )  ;
        if(   K==1  &&   vl<=nums[i] && nums[i]<=vr   &&   pl<=nums[i] && nums[i]<=pr  )
            rA -- ;
    }
    rB = (vr-vl+1LL) * (pr-pl+1LL) ;

    printf("%0.12lf\n", rA/(rB*1.0)  ) ;

    return 0 ;
}
