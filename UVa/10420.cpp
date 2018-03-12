#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std ;

map <string, int> cnt ;

int main() {
    int N ;
    char tmp[80], nom[80] ;

    gets( tmp ) ;
    sscanf( tmp, "%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	gets( tmp ) ;
	sscanf( tmp, "%s", nom ) ;
	string cty = nom ;
	if( cnt.find(cty) == cnt.end()  )
	    cnt[cty] = 0 ;
	cnt[cty] ++ ;
    }

    for( map <string, int>::iterator it=cnt.begin(); it!=cnt.end(); it++ ) 
	printf("%s %d\n", (it->first).c_str(), it->second ) ;
    
    return 0 ;
}
