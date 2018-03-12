#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <queue>
using namespace std ;
typedef unsigned long long ull ;
#define mult 62

void norm( string &S ) {
    for( int i=S.size()-1; i>=0; i-- ) {
        if( S[i]>='A' && S[i]<='Z' )
            S[i] = S[i]-'A' ;
        else if( S[i]>='a' && S[i]<='z' )
            S[i] = S[i]-'a'+26 ;
        else
            S[i] = S[i]-'0'+52 ;
    }
}

ull hash( string &W ) {
    ull carg=1ULL, res=0ULL ;
    for( int i=W.size()-1; i>=0; i--, carg*=mult )
        res += W[i]*carg ;
    return res ;
}

set <ull> usd ;
queue <ull> qPos ;
queue <string> qStr ;
queue <int> qPath ;

int main() {
    string ini, fin ;
    int R ;
    string camb[107][2] ;
    ull pos, pFin, pos2 ;
    int tmp ;
    string S, S2 ;

    cin >> ini >> fin >> R ;
    norm(ini) ;
    norm(fin) ;
    for( int i=0; i<R; i++ ) {
        cin >> camb[i][0] >> camb[i][1] ;
        norm( camb[i][0] ) ;
        norm( camb[i][1] ) ;
    }

    pos = hash(ini) ;
    pFin = hash(fin) ;
    usd.insert(pos) ;
    qPath.push(0) ;
    qPos.push(pos) ;
    qStr.push(ini) ;
    while( !qPath.empty() ) {
        pos = qPos.front() ;
        tmp = qPath.front() ;
        S = qStr.front() ;
        qPos.pop() ;
        qPath.pop() ;
        qStr.pop() ;

        /*cout << pos << " " << tmp << ",    " ;
        for( int i=0; i<S.size(); i++ )
            printf("%d ", S[i] ) ;
        cout << endl ;*/

        if( pos==pFin ) {
            printf("%d\n", tmp ) ;
            return 0 ;
        }

        for( int i=0; i<R; i++ ) {
            if( camb[i][0].size()!=camb[i][1].size() || camb[i][0].size() > S.size()  )
                continue ;
            if(   S.substr( S.size()-camb[i][0].size(), camb[i][0].size() ) != camb[i][0]    )
                continue ;
            S2 = S.substr( 0, S.size()-camb[i][0].size()  )  +   camb[i][1]  ;
            pos2 = hash(S2) ;
            if( usd.find(pos2) != usd.end()  )
                continue ;
            qPath.push(tmp+1) ;
            qPos.push(pos2) ;
            qStr.push(S2) ;
            usd.insert(pos2) ;
        }
    }

    printf("-1\n" ) ;

    return 0 ;
}
