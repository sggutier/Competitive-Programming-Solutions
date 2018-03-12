#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std ;
#define par pair<int,int>
#define x first
#define y second
#define par2 pair<par,in>

int area(  par A, par B, par C )  {
    int i, j ;
    int res = 0 ;
    par arr[3] ;

    arr[0] = A ;
    arr[1] = B ;
    arr[2] = C ;
    for( i=0; i<3; i++ ) {
        res += arr[i].x*arr[(i+1)%3].y  -  arr[i].y*arr[(i+1)%3].x  ;
    }

    return res ;
}


int dis( par A, par B, par C )   {
	int Z = area( A, B, C ), X=(A.x-B.x),  Y =(A.y-B.y) ;
	return   (Z*Z)  /  (     X*X + Y*Y     )   ;
}


int N, N2, W ;
par coor2[50000] ;
par coor[50000] ;
par convex[100001] ;



int main() {
    int i, j ;
    int res = (1<<30),  tmp ;
    N = 0 ;

    scanf("%d",&N2 ) ;
    for( i=0; i<N2; i++ ) {
        scanf("%d%d",&coor2[i].x,&coor2[i].y ) ;
    }

    sort( coor2, coor2+N2 ) ;
    for( i=0; i<N2; i++ ) {
		if( i  &&  coor2[i]==coor2[i-1]  )
			continue ;
		coor[N++] = coor2[i] ;
	}
    
    convex[0] = coor[0] ;
    convex[1] = coor[1] ;
    W = 2 ;
    for( i=2; i<N; i++ ) {
        while(  W>=2 && area( convex[W-2], convex[W-1], coor[i] ) <0   )  {
            W -- ;
        }
        convex[ W ] = coor[i] ;
        W ++ ;
    }
    for( i=N-2; i>=0; i-- ) {
        while(  W>=2 && area( convex[W-2], convex[W-1], coor[i] ) <0   )  {
            W -- ;
        }
        convex[ W ] = coor[i] ;
        W ++ ;
    }
	W -- ;

    for( i=0; i<W; i++ ) {
		tmp = 0 ;
		for( j=0; j<W; j++ ) {
			tmp = max( tmp, dis( convex[i], convex[(i+1)%W],  convex[j]  )    )  ;
		}
		res = min( res, tmp ) ;
	}

	printf("%d\n",res ) ;


    return 0 ;
}
