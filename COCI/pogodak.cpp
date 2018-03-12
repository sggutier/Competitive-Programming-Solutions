#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;

int mat[6][4] = {   {2, 3, 5, 4},
					{1, 4, 6, 3},
					{1, 2, 6, 5},
					{2, 3, 5, 4},
					{2, 3, 5, 4},
					{2, 3, 5, 4},
				};

void precarg() {
	for( int i=0; i<3; i++ ) {
		for( int j=0; j<4; j++ ) {
			mat[i][j] -- ;
		}
	}
	for( int i=3; i<6; i++ ) {
		for( int j=0; j<4; j++ ) {
			mat[i][j] = mat[5-i][3-j] ;
		}
	}
}

int main() {
	precarg() ;
	int rot=1, sup=0, dir=1 ;
	int R, C ;
	long long res = 0LL ;
	
	cin >> R >> C ;
	
	for( int i=0; i<R; i++ ) {
		for( int j=0; j<4; j++ ) {
			res += (C/4)*(mat[rot][j]+1) ;
		}
		for( int j=0; j<(C%4); j++, sup=(sup+4+dir)%4 ) {
			res += mat[rot][sup]+1 ;
		}
		sup=(sup+4-dir)%4 ;
		sup = mat[rot][sup] ;
		swap( rot, sup ) ;
		sup = 5-sup ;
		for( int j=0; j<4; j++ ) {
			if( mat[rot][j] == sup ) {
				sup = j ;
				break ;
			}
		}
		dir *= -1 ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
