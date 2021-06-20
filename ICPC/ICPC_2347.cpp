#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;

void mamadas( string &S ) {
    for( int i=0; i<S.size(); i++ ) 
        if( S[i]>='A' && S[i]<='Z' ) 
            S[i] = S[i]-'A' + 'a' ;
}

int main() {
    string h1, h2, w, S ;
    char arr[1000] ;

    while( gets(arr) ) {
        int flg = 0, x, y ;
        S = arr ;
        w = "" ;
        h1 = "" ;
        h2 = "" ;
        for( int i=0; i<S.size(); i++ ) {
            if( S[i]==' ' ) {
                w = S.substr( i+1, S.size()-i-1 ) ;
                break ;
            }
            if( S[i]==':' ) {
                flg ++ ;
                continue ;
            }
            if( flg )
                h2 += S[i] ;
            else
                h1 += S[i] ;
        }
        sscanf( S.c_str(), "%d:%d", &x, &y ) ;

        mamadas( w ) ;
        mamadas( h1 ) ;
        mamadas( h2 ) ;

        if( h1.size()>2 || h2.size()!=2 || x>23 || x<0 || y>59 || y<0 || (w!="" && w!="hrs" && w!="am"  && w!="pm"  ) || ((x<1 || x>12) && (w=="am" || w=="pm"))  )
            printf("INVALID\n" ) ;
        else
            printf("VALID\n" ) ;

    }

    return 0 ;
}


