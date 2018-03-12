#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	int pos[11] ;
	string arr[11] ;
	int N ;

	cin >> N ;
	for( int i=2; i<=N; i++ ) {
		pos[i] = 0 ;
		cin >> arr[i] ;
	}
	
	while( 1 ) {
		int x=-1, y=-1 ;
		for( int i=2; i<=N; i++ ) {
			if( arr[i].size()<=pos[i] )
				continue ;
			if( arr[i][pos[i]]=='1' ) {
				x = 1 ;
				y = i ;
				break ;
			}
			int j=arr[i][pos[i]]-'0' ;
			if( arr[j].size()<=pos[j] )
				continue ;
			if( arr[j][pos[j]]-'0' != i )
				continue ;
			x = i ;
			y = j ;	
			break ;
		}
		if( x==-1 && y==-1 )
        	break ; 
        if( x==1 ) {
        	printf("%d",y ) ;
        } 
        else
			pos[x] ++ ;
        pos[y] ++ ;
	}

	cout << endl ;	

	return 0 ;
}
