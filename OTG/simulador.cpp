#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 1005

int main() {
    int N ;
    int inst[lim], reg[lim] ;
    int a, b, c ;
    int i, pos ;

    for( i=0; i<10; i++ )
        reg[i] = 0 ;
	for( i=0; i<1000; i++ )	
		inst[i] = 0 ;

    scanf("%d",&N ) ;
    for( i=0; i<N; i++ ) {
        scanf("%d", &inst[i] ) ;
    }

    for( i=0, pos=0; pos<1000 && pos>=0; pos++  )  {


        i ++ ;
        c = (inst[pos]/1)%10 ;
        b = (inst[pos]/10)%10 ;
        a = (inst[pos]/100)%10 ;

        if( a==0 ) {
            if( b==0 ) {
                break ;
            }
            else if( b==1 ) {
                reg[c] -- ;
                reg[c] = ( reg[c] + 1000 ) % 1000 ;
            }
            else {
                pos = reg[c] ;
                pos -- ;
            }
        }
        else if( a==1 ) {
            reg[b] = c ;
        }
        else if( a==2 ) {
            reg[b] += c ;
            reg[b] = ( reg[b] + 1000 ) % 1000 ;
        }
        else if( a==3 ) {
            reg[b] *= c ;
            reg[b] = ( reg[b] + 1000 ) % 1000 ;
        }
        else if( a==4 ) {
            reg[b] = reg[c] ;
        }
        else if( a==5 ) {
            reg[b] += reg[c] ;
            reg[b] = ( reg[b] + 1000 ) % 1000 ;
        }
        else if( a==6 ) {
            swap( reg[b], reg[c] ) ;
        }
        else if( a==7 ) {
            reg[b] = inst[ reg[c] ] ;
        }
        else if( a==8 ) {
            inst[ reg[c] ] = reg[b] ;
        }
        else if( a==9 ) {
            if( reg[c] ) {
                pos = reg[b] ;
                pos -- ;
            }
        }
    }

    printf("%d\n", i ) ;
    for( i=0; i<10; i++ ) {
        printf("%d\n", reg[i] ) ;
    }

    return 0 ;
}
