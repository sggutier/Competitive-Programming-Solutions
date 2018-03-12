#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std ;

int N, K, cP ;
string P ;
int DP[105][105] ;
char DP2[105][105] ;

int maxPref( char c, int pos ) {
    string S ;
    S = P.substr( 0, pos-1 ) ;
    S += c ;
    for( int i=0; i<pos; i++ ) {
        if(  P.substr(0,pos-i) == S.substr(i,pos-i)  )  {
            return pos-i ;
        }
    }
    return 0 ;
}

int maxPref2( int W, char c, int pos ) {
    string S ;
    S = P.substr( 0, pos-1 ) ;
    S += c ;
    for( int i=0; i<pos; i++ ) {
        if(  P.substr(0,pos-i) == S.substr(i,pos-i)  )  {
            DP[W][pos-i] = pos ;
        }
    }
    DP[W][0] = pos ;
}

int main() {
    char sel[105] ;
    char S[105] ;
    int i, j, c ;
    
    scanf("%d%d",&N,&K ) ;
    cin >> P ;
    cin >> sel ;
    
    cP = P.size() ;
    for( i=N-1; i>=cP-1; i-- ) {
        sel[i] = sel[i-cP+1] ;
    }
    for( ; i>=0; i-- ) {
        sel[i] = '0' ;
    }
    
    DP[0][0] = 1 ;
    DP[0][1] = 1 ;
    DP2[0][1] = P[0] ;
    DP2[0][0] = 'a' ;
    if( P[0]=='a' ) {
        if( K==1 ) {
            DP[0][0] = 0 ;
        }
        else
            DP2[0][0] = 'b' ;
    }
    for( i=0; i<N; i++ ) {
        if( sel[i] == '1' ) {
            if( DP[i][cP] == 0 ) {
                printf("No solution\n");
                return 0;
            }
            j = cP ;
            if( DP[i][j] ) {
                for( c=0; c<K; c++ ) {
                    DP[i+1][ maxPref( c+'a', j+1 ) ] = j+1 ;
                    DP2[i+1][ maxPref( c+'a', j+1 ) ] = c+'a' ;
                    //maxPref2( i+1, c+'a', j+1 ) ;
                }
            }
        }
        else {
            for( j=0; j<cP && DP[i][j]==0; j++ ) {
            }
            if( j==cP ) {
                printf("No solution\n");
                return 0;
            }
            for( ; j<cP; j++ ) {
                if( DP[i][j] ) {
                    for( c=0; c<K; c++ ) {
                        if( DP[i][j] ) {
                            DP[i+1][ maxPref( c+'a', j+1 ) ] = j+1 ;
                            DP2[i+1][ maxPref( c+'a', j+1 ) ] = c+'a' ;
                            //maxPref2( i+1, c+'a', j+1 ) ;
                        }
                    }
                }
            }
        }
    }
    
    P = "a" + P ;
    if( P[0] == P[1] )
        P[0] = 'b' ;
   
    if( sel[N-1] == '1' ) {
        j = cP ;
    }
    else {
        i = N-1 ;
        for( j=0; j<cP && DP[i][j]==0; j++ ) {
        }
        if( j==cP ) {
            printf("No solution\n");
            return 0;
        }
    }
    for( i=N-1; i>=0; i-- ) {
        if( j==0 && K==1 ) {
            printf("No solution\n");
            return 0;
        }
        S[i] = DP2[i][j] ;
        j = DP[i][j]-1 ;
        if( j == -1 ) {
            while(1) {
            }
            printf("No solution\n");
            return 0;
        }
    }
    
    for( i=0; i<N; i++ )
        printf("%c",S[i] ) ;
    cout << endl ;
    
    return 0 ;
}
