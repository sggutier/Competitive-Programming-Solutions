#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std ;
#define lim 300005
#define par pair<int,int>
#define f first
#define s second

int main() {
	int N2, M ;
	int N=0 ;
	par arr[2*lim] ;
	int i, j, w ;
	int  Q=0,  ant=0, ant2  ;
	long long res = 0LL ;
	
	scanf("%d%d",&N2,&M ) ;
	arr[N++] = par( 0, -1 ) ;
	arr[N++] = par( 0,  1 ) ;
	while( N2 ) {
		N2 -- ;
		scanf("%d%d",&i,&j ) ;
		if( i>j ) {
			arr[N++] = par( i,  1 ) ;
			arr[N++] = par( j, -1 ) ;
		}
	}
	
	
	sort(  arr,  arr+N  ) ;
	i = 0 ;
	while( i<N ) {
		j = arr[i].f ;
		w = arr[i].s ;
		i ++ ;
		while( i<N  &&  arr[i-1].f==arr[i].f  )  {
			w += arr[i].s ;
			i ++ ;
		}
		if(  w && Q+w == 0  )   {
			res += 2LL*( j-ant2 )  ;
			res += (j-ant) ;
			ant = j ;
		}
		else if( w<0  &&  Q==0  )  {
			ant2 = j ;
		}
		Q += w ;
	}
	res += (M-ant) ;
	
	cout << res << endl ;
	
	return 0 ;
}
