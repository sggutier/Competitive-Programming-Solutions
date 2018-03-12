#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim  = 605 ;
const int lim2 = 305 ;

int N, M ;
unsigned long long upa[lim][lim], don[lim][lim] ;
unsigned long long pot3[lim2*lim2], carg[lim] ;
    char S[lim2][lim2] ;

int main() {
    unsigned long long tot ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ )
        scanf("%s", S[i] ) ;

    for( int i=1; i<=N; i++ )
        for( int j=1; j<=M; j++ )
            upa[i][j] = upa[i][j-1]*3ULL + (S[i-1][j-1]-'0') ;
    for( int i=1; i<=N; i++ )
        for( int j=M; j>=1; j-- )
            don[i][j] = don[i][j+1]*3ULL + (S[i-1][j-1]-'0') ;

    pot3[0] = 1ULL ;
    for( int i=1; i<lim2*lim2; i++ )
        pot3[i] = pot3[i-1] * 3ULL ;

    //cout << endl ;
    for( int k=min(N,M), k2, w; k>1; k-- ) {
        k2 = k/2 + k%2 ;
        w = (k+1)%2 ;
        for( int j=1; j+k-1<=M; j++ ) {

            tot = 0ULL ;
            for( int i=N; i>=1; i-- ) {
                carg[i] = (don[i][j]-pot3[k]*don[i][j+k]) + carg[i+1]*pot3[k] -   (don[i+k2][j]-pot3[k]*don[i+k2][j+k])*pot3[k*k2]   ;
            }
            for( int i=1; i+k2-1<=N; i++ ) {
                tot = tot*pot3[k] +   (upa[i][j+k-1]-pot3[k]*upa[i][j-1])   ;
                if( i>=k2 ) {
                    tot -= (upa[i-k2][j+k-1]-pot3[k]*upa[i-k2][j-1])*pot3[k*k2] ;
                }
                //cout << tot << " " << carg[i]  << endl ;

                if( tot==carg[i+w] ) {
                    int moo = 1, t=i-k2 ;
                    for( int x=0; x<k; x++ ) {
                        for( int y=0; y<k; y++ ) {
                            if( S[t+x][j-1+y]!=S[t+(k-1-x)][j-1+(k-1-y)] ) {
                                moo = 0 ;
                            }
                        }
                    }
                    if( moo ) {
                        printf("%d\n", k ) ;
                        return 0 ;
                    }
                }
            }
            //cout << "-------\n"  ;
            //getchar() ;

        }
        //cout << "-------------\n" ;
    }

    printf("-1\n" ) ;

    return 0 ;
}
