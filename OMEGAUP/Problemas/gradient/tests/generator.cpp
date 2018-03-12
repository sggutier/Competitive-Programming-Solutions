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


int N ;
int mat[2000][2000] ;

bool valdColor( int W ) {
    return 0 <= W and W<=65535 ;
}

bool valdRang( int tam, int r, int c, int S, int K, int Q ) {
    tam -- ;
    if( Q==0 ) 
	return valdColor( S + r*K ) and valdColor(S+ (r+tam)*K)  ;
    else if( Q==1 )
	return valdColor( S + c*K ) and valdColor(S+ (c+tam)*K)  ;
    else {
	Q = Q==2? -1 : 1 ;
	return valdColor(S + (r + c*Q)*K) and valdColor(S + (r + (c+tam)*Q)*K) and valdColor(S + ((r+tam) + c*Q)*K) and valdColor(S + ((r+tam) + (c+tam)*Q)*K) ;
    }
}

void pintaCuad(int tam, int tip) {
    int r = gifRand%(N-tam+1), c = gifRand%(N-tam+1) ;
    int S, K, Q ;
    // tip = gifRand%2 + 1 ;

    if( tip==0 ) {
	while( 1 ) {
	    S = gifRand%65535 ;
	    K = gifRand%65535 ;
	    if( gifRand%2 )
		K *= -1 ;
	    Q = gifRand%2 ;
	    if( valdRang( tam, r, c, S, K, Q ) )
		break ;
	}
	// cout << r << " " << c << " " << tam << " >>> "  << S << " " << K << " " << Q << endl ;
	for( int i=0; i<tam; i++ ) {
	    for( int j=0; j<tam; j++ ) {
		mat[i+r][j+c] = S + ((!Q)? i+r : j+c )*K ;
	    }
	}
    }
    else {
	while( 1 ) {
	    S = gifRand%65535 ;
	    K = gifRand%65535 ;
	    if( gifRand%2 )
		K *= -1 ;
	    Q = gifRand%2  + 2 ;
	    if( valdRang( tam, r, c, S, K, Q ) )
		break ;
	}
	Q = Q==2? -1 : 1 ;
	// cout << r << " " << c << " " << tam << " >>> "  << S << " " << K << " " << Q << endl ;
	for( int i=0; i<tam; i++ ) {
	    for( int j=0; j<tam; j++ ) {
		mat[i+r][j+c] = S + ( (i+r) + (j+c)*Q)*K ;
	    }
	}
    }
}

void generaCuads( int W, int esp ) {
    //pintaCuad( N, gifRand%2 ) ;
    for( int i=0; i<N; i++ )
	for( int j=0; j<N; j++ )
	    mat[i][j] = (i+j)%2 ;
    int res = gifRand % N + 1 ;
    for( int i=0; i<W; i++ ) {
	pintaCuad( gifRand%res, gifRand%2 ) ;
    }
    pintaCuad( res, esp ) ;
}

int main(int argc, char **argv ) {
    MT19937::seed( time(NULL) );

    if( argc<4 ) {
	return 0 ;
    }

    int minVal = atoi(argv[1]), maxVal=atoi(argv[2]), tip=atoi(argv[3]), cnt, dif=abs(minVal-maxVal) + 1 ;

    if( minVal > maxVal )
	swap( minVal, maxVal ) ;

    N = minVal + gifRand%dif ;

    cout << N << endl ;
    generaCuads( gifRand % N, tip ) ;
    for( int i=0; i<N; i++ ) {
	for( int j=0; j<N; j++ ) {
	    if( j )
		printf( " " ) ;
	    printf("%d", mat[i][j] ) ;
	}
	printf("\n" ) ;
    }
    
    return 0 ;
}
