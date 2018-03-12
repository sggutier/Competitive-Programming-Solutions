#include <cstdio>
#include <ctime>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define pto pair <long double, long double>
#define par pair<int,int>
#define x first
#define y second
#define mkp make_pair
const int inf = 1e9 ;
const double eps = 1e-9 ;
const int lim = 1e6 + 5 ;
const int dr[] = { -1, 0, 1, 0 } ;
const int dc[] = { 0, 1, 0, -1 } ;
#define lin pair< pto, pto >
#define gifRand MT19937::get()

struct MT19937 {
private:
    static mt19937_64 rng;
public:
    // This is equivalent to srand().
    static void seed(uint64_t new_seed = mt19937_64::default_seed) {
        rng.seed(new_seed);
    }

    // This is equivalent to rand().
    static uint64_t get() {
        return rng();
    }
};

mt19937_64 MT19937::rng;


/////////////

int N, E ;
set <int> usd ;
int arr[lim] ;

int main(int argc, char **argv ) {
    MT19937::seed( time(NULL) );

    if( argc<3 ) {
	return 0 ;
    }

    int minVal = atoi(argv[1]), maxVal=atoi(argv[2]), dif=abs(minVal-maxVal) + 1 ;
    int minVal2, maxVal2, dif2 ;

    if( argc>=5 ) {	
	minVal2 = atoi(argv[3]), maxVal2=atoi(argv[4]), dif2=abs(minVal-maxVal) + 1 ;
	minVal2 = max( minVal2, N ) ;
	if( maxVal2!=-1 ) {
	    if( minVal2 > maxVal2 )
		swap( minVal2, maxVal2 ) ;
	    E = minVal2 + gifRand%dif2 ;
	}
    }

    if( minVal > maxVal )
	swap( minVal, maxVal ) ;

    N = minVal + gifRand%dif ;
    E = max( E, (N>1? N : 0) ) ;
    if( N==1 )
	E = 0 ;

    cout << N << " " << E << endl ;
    arr[0] = gifRand%N ;
    usd.insert( arr[0] ) ;
    for( int i=1; i<N; i++ )  {
	arr[i]= gifRand%N ;
	while( usd.count(arr[i]) )
	    arr[i] = gifRand%N ;
	usd.insert( arr[i] ) ;
	printf("%d %d %d\n", arr[gifRand%i] + 1, arr[i] + 1, gifRand%int(1e1) ) ;
    }

    if( N>1 ) {
	for( int i=N-1; i<E; i++ ) {
	    int a, b ;
	    do {
		a = gifRand%N ;
		b = gifRand%N ;
	    } while( a== b ) ;
	    printf("%d %d %d\n", a+1, b+1, gifRand%int(1e1) ) ;
	}
    }
    
    return 0 ;
}
