#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <map>
using namespace std ;
#define par pair<long long,long long>
#define x first
#define y second

//map <par,int> rep ;
//par res[200005] ;

int main() {
	long long N, W ;
	par pos, arr[100005] ;
	int i, j ;
	
	cin >> N >> W ;
	cin >> pos.x >> pos.y ;
	for( i=0; i<N ;i++ ) {
		cin >> arr[i].x >> arr[i].y ; 
	}
	
	i = 0 ;
	W %= 2LL*N ;
	while( i<W   ) {
		//res[i] = pos ;
		//rep[pos] = i ;
		pos.x = 2LL*arr[i%N].x-pos.x ;
		pos.y = 2LL*arr[i%N].y-pos.y ;
		i++ ;
	}
	
	cout << pos.x << " " << pos.y << endl ;
	
	return 0 ;
}
