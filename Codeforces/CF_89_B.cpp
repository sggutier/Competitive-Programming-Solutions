#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <list>
#include <utility>
using namespace std ;
typedef pair<long long,long long> par ;
#define f first
#define s second


struct widg {
	list <int> hijos ;
	list <int> padre ;
	par tam ;
	int bord, esp, tip ;
	int nH ;
	widg() {
	}
	widg( par a, int b, int c, int d ) {
		nH = 0 ;
		tam = a ;
		bord = b ;
		esp = c ;
		tip = d ;
	}
} ;


	widg  dir[1000] ;
	int R ;
	string rev[1000] ;
	map <string, int >  ref  ;

void upd( int pos ) {
	
		
	for( list <int> :: iterator it = dir[pos].padre.begin();  it!=dir[pos].padre.end();  it++  ) 
		dir[ *it ].nH -- ;
	if( dir[pos].hijos.empty()   )
		return ;
	
	if( dir[pos].tip == 1  )  {
		long long a = 0LL + ( dir[pos].hijos.size()-1 )*dir[pos].esp ;
		long long b = 0LL ;
		for(  list <int> :: iterator it = dir[pos].hijos.begin();  it!=dir[pos].hijos.end();  it++  ) {
			a += dir[*it].tam.f ;
			b = max(  b,  dir[*it].tam.s  );
		} 
		a += dir[pos].bord*2LL ;
		b += dir[pos].bord*2LL ;
		dir[pos].tam.f = a ;
		dir[pos].tam.s = b ;
	}
	else if( dir[pos].tip == 0  )  {
		
		long long b = 0LL + ( dir[pos].hijos.size()-1 )*dir[pos].esp ;
		long long a = 0LL ;
		for(  list <int> :: iterator it = dir[pos].hijos.begin();  it!=dir[pos].hijos.end();  it++  ) {
			a = max(  a,  dir[*it].tam.f  );
			b += dir[*it].tam.s ;
		} 
		a += dir[pos].bord*2LL ;
		b += dir[pos].bord*2LL ;
		dir[pos].tam.f = a ;
		dir[pos].tam.s = b ;
	}
}


int main() {
	//freopen( "89B.in", "r", stdin ) ;
	
	int N ;
	R = 0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		string s ;
		char c ;
		scanf("%c", &c ) ;
		scanf("%c", &c ) ;
		while( c!=' ' && c!='.' ) {
			s += c ;
			scanf("%c", &c ) ;
		}
		
		
		if( s=="VBox"  )  {
			string z ;
			cin >> z ;
			
			if( ref.find(z) == ref.end()  )  {
				ref[z] = R ;
				rev[R] = z ;
				R ++ ;
			}
			int y = ref[z] ;
			
			dir[y] = widg( par(0LL,0LL),  0,  0, 0   )   ;
		}
		else if( s=="HBox" ) {
			string z ;
			cin >> z ;
			
			if( ref.find(z) == ref.end()  )  {
				ref[z] = R ;
				rev[R] = z ;
				R ++ ;
			}
			int y = ref[z] ;
			
			dir[y] = widg( par(0LL,0LL),  0,  0, 1   )   ;
		}
		else {
			
			string z ;
			scanf("%c", &c ) ;
			while( c!='('  ) {
				z += c ;
				scanf("%c", &c ) ;
			}
			if( s=="Widget" ) {
				int a, b ;
				scanf("%d,%d)", &a, &b ) ;
				
				if( ref.find(z) == ref.end()  )  {
					ref[z] = R ;
					rev[R] = z ;
					R ++ ;
				}
				int y = ref[z] ;
				
				dir[y] = widg( par(0LL+a,0LL+b),  0,  0, -1   )   ;
			}
			else {
				if( ref.find(s) == ref.end()  )  {
					ref[s] = R ;
					rev[R] = s ;
					R ++ ;
				}
				int x = ref[s] ;
				
				if( z=="pack" ) {
					string w ;
					scanf("%c", &c ) ;
					while( c!=')' ) {
						w += c ;
						scanf("%c", &c ) ;
					}
					
					
					if( ref.find(w) == ref.end()  )  {
						ref[w] = R ;
						rev[R] = w ;
						R ++ ;
					}
					int y = ref[w] ;
					
					
					dir[y].padre.push_back( x );
					dir[x].hijos.push_back( y ) ;
					
				}
				else if( z=="set_border" )  {
					int a ;
					scanf("%d)", &a ) ;
					dir[x].bord = a ;
				}
				else {
					int a ;
					scanf("%d)", &a ) ;
					dir[x].esp = a ;
				}
			}
		}
	}
	
	for(  int i=0; i<R; i++  )  {
		dir[i].nH = dir[i].hijos.size() ;
	}
	
	N = R ;
	while( N ) {
		for(  int i=0; i<R; i++  )  {
			if(  dir[i].nH  != 0  )
				continue ;
			dir[i].nH = -1 ;
			N -- ;
			upd( i ) ;
		}
	}
	
	for( map <string, int > :: iterator it = ref.begin();  it != ref.end();  it++  )  {
		int pos = (*it).s ;
		cout << (*it).f << " " ;
		cout << dir[pos].tam.f << " " ;
		cout << dir[pos].tam.s << endl ;
	}
	
	
	return 0 ;
}
