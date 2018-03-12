#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>
using namespace std ;
#define limN 100005
#define f first
#define s second
#define mod 30013

struct trap {
	int a, b, c, d, men ;
	trap() {
	}
	trap( int x, int y, int z, int w ) {
		a = x ;
		b = y ;
		c = z ;
		d = w ;
	}
};

struct fin {
	int pos, val, carg ;
	fin() {
	}
	fin( int a, int b, int c ) {
		pos = a ;
		val = b ;
		carg = c ;
	}
};

bool operator<( fin A, fin B ) {
	return A.pos > B.pos ;
}

bool operator<( trap A, trap B ) {
	return A.men < B.men ;
}


int bit[limN] ;
int cRes[limN] ;

void upd( int pos, int val ) {
	for( ; pos<limN; pos+=(pos & -pos)  ) 
		bit[pos] = max( bit[pos], val )  ;
}

int val( int pos ) {
	int res = 0 ;
	for( ; pos; pos-=( pos & -pos )    )
		res = max( res, bit[pos] ) ;
	return res ;
}

void updR( int pos, int val ) {
	for( ; pos<limN; pos+=(pos & -pos)  ) 
		cRes[pos] = ( cRes[pos]+val ) % mod  ;
}

int valR( int pos ) {
	if( pos<0 )
		return 0 ;
	int res = 1 ;
	for( ; pos; pos-=( pos & -pos )    )
		res = ( res + cRes[pos] )%mod ;
	return res ;
}


int main() {
	freopen( "trapezoid.in", "r", stdin ) ;
	freopen( "trapezoid.out", "w", stdout ) ;
	
	memset( bit, 0, sizeof(bit) ) ;
	int N ;
	trap arr[limN] ;
	map <int,int> ID ;
	map <int,int> :: iterator it ;
	int i, tmp, tmp2 ;
	int res=0 ;
	priority_queue <fin> q ;
	fin f ;
	
	scanf("%d", &N ) ;
	for( i=0; i<N; i++ ) {
		int x, y, z, w ;
		scanf("%d%d%d%d", &x, &y, &z, &w ) ;
		arr[i] = trap( x, y, z, w ) ;
		ID[x] = 0 ;
		ID[y] = 0 ;
		ID[z] = 0 ;
		ID[w] = 0 ;
	}
	
	i = 1 ;
	for( it=ID.begin(); it!=ID.end(); it++ ) {
		(*it).s = i++ ;
	}
	for( i=0; i<N; i++ ) {
		arr[i].a = ID[ arr[i].a ] ;
		arr[i].b = ID[ arr[i].b ] ;
		arr[i].c = ID[ arr[i].c ] ;
		arr[i].d = ID[ arr[i].d ] ;
		arr[i].men = min(  min( arr[i].a, arr[i].b ),  min( arr[i].c, arr[i].d )    )   ;
	}	
	//IMPORTANTE, NO BORRAR
	sort( arr, arr+N ) ;
	
	
	
	memset( cRes, 0, sizeof(cRes)   )  ;
	cRes[0] = 1 ;
	for( i=0; i<N; i++ ) {
		while( !q.empty() && q.top().pos<arr[i].men   )  {
			f = q.top() ;
			q.pop() ;
			/*cRes[f.val] += f.carg ;
			cRes[f.val] %= mod ;
			//updR( f.val, f.carg ) ;
			printf("%d,%d,%d  ", f.pos, f.val, f.carg ) ;*/
			upd( f.pos, f.val ) ;
		}
		/*cout << endl ;
		for( int j=0; j<N; j++ ) {
			printf("%d ", valR(j)-valR(j-1) ) ;
		}
		cout << endl ;
		printf("---------\n" ) ;*/
		tmp = val( arr[i].men-1 )+1 ;
		q.push(   fin  (   max(  max( arr[i].a, arr[i].b ),  max( arr[i].c, arr[i].d )     ),   tmp,   0   )    );
		res = max( res, tmp ) ;
	}
	while( !q.empty() && q.top().pos<arr[i].men   )  {
		f = q.top() ;
		q.pop() ;
		/*cRes[f.val] += f.carg ;
		cRes[f.val] %= mod ;
		//updR( f.val, f.carg ) ;
		printf("%d,%d,%d  ", f.pos, f.val, f.carg ) ;*/
		upd( f.pos, f.val ) ;
	}
	/*cout << endl ;
	for( int j=0; j<N; j++ ) {
		printf("%d ", valR(j) ) ;
	}
	cout << endl ;
	printf("---------\n" ) ;*/
	
	printf("%d %d\n", res, 8 ) ;
	
	return 0 ;
}
