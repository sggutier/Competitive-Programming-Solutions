#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main()  {
	string notas[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H" } ;
	int arr[3] ;
	string x, y, z ;
	int a, b, c ;
	int i ;
	
	cin >> x >> y >> z ;
	
	for( arr[0]=0; notas[arr[0]]!=x; arr[0]++ ) ;
	for( arr[1]=0; notas[arr[1]]!=y; arr[1]++ ) ;
	for( arr[2]=0; notas[arr[2]]!=z; arr[2]++ ) ;
	
	sort( arr, arr+3 ) ;
	
	do {
		a = arr[0] ;
		b = arr[1] ;
		c = arr[2] ;
		while( b<a )
			b += 12 ;
		while( c<b )
			c += 12 ;
		if( b-a == 4 && c-b == 3  )  {
			cout << "major" << endl ;
			return 0 ;
		}
		if( b-a == 3 && c-b == 4  )  {
			cout << "minor" << endl ;
			return 0 ;
		}
	} while( next_permutation( arr, arr+3 )   ) ;
	
	cout << "strange" << endl ;
	
	return 0 ;
}
