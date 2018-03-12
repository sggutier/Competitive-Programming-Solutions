#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;

string A ;
string S[9] ;
int ren[9][9], col[9][9], cud[9][9] ;
int X[100], Y[100], Z[100] ;
int W = 0, R ;
int res = 0 ;

void busca( int pos ) {
    if( pos==W ) {
        cout << pos << endl ;
        R = 1 ;
        return ;
    }
    for( int i=0; i<9 && !R; i++ ) {
        if( !ren[ X[pos] ][i]  && !col[ Y[pos] ][i]  && !cud[ Z[pos] ][i]   )   {
            ren[ X[pos] ][i] ++ ;
            col[ Y[pos] ][i] ++ ;
            cud[ Z[pos] ][i] ++ ;
            //cout << ">>" << X[pos] << " " << Y[pos] << " " << Z[pos] << " "  << i+1 << endl ;
            //getchar() ;
            S[ X[pos] ][ Y[pos] ] = i+1 ;
            busca( pos+1 ) ;
            ren[ X[pos] ][i] -- ;
            col[ Y[pos] ][i] -- ;
            cud[ Z[pos] ][i] -- ;
        }
    }
}

void solve() {
    W = 0 ;
    R = 0 ;
    for( int i=0; i<9; i++ ) {
        for( int j=0; j<9; j++ ) {
            ren[i][j] = 0 ;
            col[i][j] = 0 ;
            cud[i][j] = 0 ;
        }
    }
    for( int i=0; i<9; i++ ) {
        for( int j=0; j<9; j++ ) {
            S[i][j] -= '0' ;
            if( S[i][j]==0 ) {
                X[W] = i ;
                Y[W] = j ;
                Z[W] = (i/3)*3 + j/3 ;
                W ++ ;
                continue ;
            }
            ren[i][ S[i][j]-1 ] ++ ;
            col[j][ S[i][j]-1 ] ++ ;
            cud[(i/3)*3 + j/3][ S[i][j]-1 ] ++ ;
        }
    }

    busca( 0 ) ;

    cout << A << endl ;
    for( int i=0; i<9; i++ ) {
        for( int j=0; j<9; j++ )
            printf("%d", S[i][j] ) ;
        printf("\n" ) ;
    }
    printf("---------\n" ) ;

    res += S[0][0]*100 + S[0][1]*10 + S[0][2] ;
}

int main() {
    freopen( "sudoku.txt", "r", stdin ) ;

    char oht[100] ;

    while( scanf("%s", oht) != EOF ) {
        A = oht ;
        scanf("%s", oht) ;
        A = A + " " + oht ;
        for( int i=0; i<9; i++ ) {
            scanf("%s", oht ) ;
            S[i] = oht ;
        }

        solve() ;
    }

    cout << res << endl ;

    return 0 ;
}
