#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std ;

int main() {
    string S ;
    char res[5][1000] ;
    int dr[] = { -2, -1, -1, 0, 0, 1, 1, 2 } ;
    int dc[] = { 0, -1, 1, -2, 2, -1, 1, 0 } ;

    cin >> S ;

    memset( res, '.', sizeof(res) ) ;
    for( int i=0; i<S.size(); i++ ) {
        int r=2, c=i*4 + 2 ;
        res[r][c] = S[i] ;
        for( int d=0, x, y; d<8; d++ ) {
            x = dr[d] + r ;
            y = dc[d] + c ;
            if( i%3!=2 && res[x][y]=='.' )
                res[x][y] = '#' ;
            else if( i%3==2 )
                res[x][y] = '*' ;
        }
    }

    for( int i=0; i<5; i++ ) {
        for( int j=0; j<S.size()*4+1; j++ )
            printf("%c", res[i][j] ) ;
        printf("\n" ) ;
    }

    return 0 ;
}
