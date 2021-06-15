#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int N, K ;
string S[100000], tmp ;

int main() {
    int i ;

    scanf("%d%d", &N, &K ) ;
    for( int i=0; i<4*N; i++ ) {
        cin >> tmp ;
        for( int j=0; j<tmp.size(); j++ )
            if( tmp[j] == 'a' || tmp[j] == 'e'  || tmp[j] == 'i' || tmp[j] == 'o' || tmp[j] == 'u'  )
                S[i] += tmp[j] ;
    }

    for( int i=0; i<4*N; i++ ) {
        if( S[i].size()<K  ) {
            cout << "NO" << endl ;
            return 0 ;
        }
        S[i] = S[i].substr( S[i].size()-K, K ) ;
    }

    for( i=0; i<N; i++ ) {
        int j ;
        for( j=1; j<4 && S[i*4+j]==S[i*4+j-1]; j++ ) ;
        if( j!=4 ) {
            break ;
        }
    }
    if( i==N ) {
        cout << "aaaa" << endl ;
        return 0 ;
    }

    for( i=0; i<N; i++ ) {
        if( S[i*4+0]==S[i*4+2] && S[i*4+1]==S[i*4+3]  ) {
        }
        else {
            break ;
        }
    }
    if( i==N ) {
        cout << "abab" << endl ;
        return 0 ;
    }

    for( i=0; i<N; i++ ) {
        if( S[i*4+0]==S[i*4+1] && S[i*4+2]==S[i*4+3]  ) {
        }
        else {
            break ;
        }
    }
    if( i==N ) {
        cout << "aabb" << endl ;
        return 0 ;
    }

    for( i=0; i<N; i++ ) {
        if( S[i*4+0]==S[i*4+3] && S[i*4+1]==S[i*4+2]  ) {
        }
        else {
            break ;
        }
    }
    if( i==N ) {
        cout << "abba" << endl ;
        return 0 ;
    }

    cout << "NO" << endl ;

    return 0 ;
}
