#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
#define lim 10005

int N ;
int nums[lim], nums2[lim] ;
int ord[lim], ord2[lim] ;
int res3[lim], res4[lim] ;


void buscaRes( int arr[], int sgn[], int res[] ) {
    int W=0, R=0 ;
    int sum[lim] ;

    sort( arr, arr+N ) ;
    for( int i=0; i<N; i++ ) {
        if( i==0 || sgn[i]!=sgn[i-1] )
            W ++ ;
        if( i%2==0 )
            sum[i] += arr[i] ;
        else
            sum[i] -= arr[i] ;
        if( i )
            sum[i] += sum[i-1] ;
    }

    W = N-W ;
    for( int i=0, j, k=1, carg=0; i<N; i+=j, k*=-1 ) {
        res[i] = arr[W++]*k ;
        carg += res[i] ;
        for( j=1; i+j<N && sgn[i+j]==sgn[i+j-1]; j++ ) ;

        if( j==1 )
            continue ;

        int tmp = sum[i+j-1], k2=1 ;
        if( R )
            tmp -= sum[R-1] ;

        if( abs(carg+tmp) > abs(carg-tmp)  )
            k2 = -1 ;

        for( j=1; i+j<N && sgn[i+j]==sgn[i+j-1]; j++, k2*=-1, R++ ) {
            //res[i+j] = arr[R]*k2 ;
            res[i+j] = 9 ;
        }
    }
}


int main() {
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &nums[i] ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &nums2[i] ) ;

    for( int i=0; i<N; i++ ) {
        scanf("%d", &ord[i] ) ;
        ord[i] -- ;
        ord2[i] = ord[i]%2 ;
        ord[i] = ord[i]%4 < 2 ;
    }


    buscaRes( nums, ord, res3 ) ;
    buscaRes( nums2, ord2, res4 ) ;

    for( int i=0; i<N; i++ ) {
        if( res3[i]<0 )
            printf("%d ", res3[i] ) ;
        else
            printf("+%d ", res3[i] ) ;
        if( res4[i]<0 )
            printf("%d\n", res4[i] ) ;
        else
            printf("+%d\n", res4[i] ) ;
    }

    return 0 ;
}
