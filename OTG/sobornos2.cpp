#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int N ;
int minS[51][(1<<16)] ;
int res[50] ;
int inf[50] ;
int quita[50][50] ;
int i, j, pot ;

void memo( int pos, int masc ) {

    if(  minS[pos][masc]!=-1  )
        return ;

    if( pos==N ) {
		minS[pos][masc] = (1<<30) ;
        for( i=max(N-8,0); i<N; i++ )
            if( res[i]>0 )
                return ;
		minS[pos][masc] = 0 ;
        return ;
    }

    minS[pos][masc] = (1<<30) ;
    for( i=max(pos-8,0);  i<pos;  i++  )
        res[i] -= quita[pos][i] ;
    for( i=min(pos+8,N-1);  i>=pos;  i--  )
        res[i] -= quita[pos][i] ;


	memo(  pos+1,  (masc<<1)+1  ) ;
	minS[pos][masc] = min( minS[pos][masc],  minS[pos+1][(masc<<1)+1] +1 )     ;

    for( i=max(pos-8,0);  i<pos;  i++  )
        res[i] += quita[pos][i] ;
    for( i=min(pos+8,N-1);  i>=pos;  i--  )
        res[i] += quita[pos][i] ;

    if( pos<8 || res[pos-8]<=0  ) {
		memo(  pos+1,  (masc<<1)  ) ;
        minS[pos][masc] = min( minS[pos][masc],  minS[pos+1][masc<<1]  )    ;
	}

    return ;
}

int main() {


    for( i=(1<<16)-1; i>=0; i-- )
        for( j=50; j>=0; j-- )
            minS[j][i] = -1 ;

    scanf("%d",&N ) ;
    for( i=0; i<N; i++ )
        scanf("%d",&inf[i] ) ;
    for( i=0; i<N; i++ )
        scanf("%d",&res[i] ) ;

    for( i=0; i<N; i++ ) {
        quita[i][i] = inf[i] ;
        for( j=i-1, pot=2; j>=0 && inf[i]/pot;  j--, pot*=2  )
            quita[i][j] = inf[i]/pot ;
        for( j=i+1, pot=2; j<N  && inf[i]/pot;  j++, pot*=2  )
            quita[i][j] = inf[i]/pot ;
    }

	memo( 0, 0 ) ;
    printf("%d\n",minS[0][0]  ) ;

    return 0 ;
}
