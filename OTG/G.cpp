#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std ;
#define par pair<double,double>
#define x first
#define y second
#define par2 pair<par,double>

int area(  par A, par B, par C )  {
    int i, j ;
    double res = 0 ;
    par arr[3] ;

    arr[0] = A ;
    arr[1] = B ;
    arr[2] = C ;
    for( i=0; i<3; i++ ) {
        res += arr[i].x*arr[(i+1)%3].y  -  arr[i].y*arr[(i+1)%3].x  ;
    }

    if( res>0 )
        return 1 ;
    else if( res<0  )
        return -1 ;
    else
        return 0 ;
}

bool interSegm(  par iniA, par iniB,  par finA, par finB  )   {
    int L, R ;
    L = area( iniA, iniB, finA ) ;
    R = area( iniA, iniB, finB ) ;
    if(  L!=R  )  {
        L = area( finA, finB, iniA ) ;
        R = area( finA, finB, iniB ) ;
        return L!=R  || ( !R && !L )  ;
    }
    else if( !R && !L )  {
        L = area( finA, finB, iniA ) ;
        R = area( finA, finB, iniB ) ;
        if(  L!=R  )
            return 1 ;
        L = min( iniA.x,  iniB.x ) ;
        R = max( iniA.x,  iniB.x ) ;
        if(  finA.x >= L  &&  finA.x <=R  )   {
            L = min( iniA.y,  iniB.y ) ;
            R = max( iniA.y,  iniB.y ) ;
            if(  finA.y >= L  &&  finA.y <=R  )
                return 1 ;
        }
        L = min( iniA.x,  iniB.x ) ;
        R = max( iniA.x,  iniB.x ) ;
        if(  finB.x >= L  &&  finB.x <=R  )   {
            L = min( iniA.y,  iniB.y ) ;
            R = max( iniA.y,  iniB.y ) ;
            if(  finB.y >= L  &&  finB.y <=R  )
                return 1 ;
        }
        return 0 ;
    }
    return 0 ;
}

par operator-( par A, par B ) {
	return par( A.x-B.x, A.y-B.y ) ;
}

double operator^( par A, par B ) {
	return A.x*B.y - A.y*B.x ;
}

double operator*( par A, par B ) {
	return A.x*B.x + A.y*B.y ;
}

double disSegm(  par A, par B, par C ) {
	double dist = ((B-A)^(C-A)) / sqrt((B-A)*(B-A)) ;
	int dot1 = (C-B)*(B-A);
	if(dot1 > 0)
		return sqrt((B-C)*(B-C));
	int dot2 = (C-A)*(A-B);
	if(dot2 > 0)
		return sqrt((A-C)*(A-C));
	return abs(dist);
}
 


int N, W ;
par coor[50000] ;
par convex[100001] ;


int main() {
    int i, j ;
    int ini, fin, piv ;
    double res = (1<<30)*1.0, tmp ;

    scanf("%d",&N ) ;
    for( i=0; i<N; i++ ) {
        scanf("%lf%lf",&coor[i].x,&coor[i].y ) ;
    }

    sort( coor, coor+N ) ;
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
		printf("->%lf %lf\n",convex[i].x,convex[i].y ) ;
		ini = 1 ;
		fin = W-1 ;
		while( ini<fin ) {
			piv = (ini+fin)/2 ;
			if(   disSegm( convex[i], convex[(i+1)%W],  convex[(i+piv)%W]  )  >=  disSegm( convex[i], convex[(i+1)%W],  convex[(i+piv+1)%W]  )     )    
				fin = piv ;
			else 
				ini = piv+1 ;
		}
		res = min( res, disSegm( convex[i], convex[(i+1)%W],  convex[(i+ini)%W]  )    ) ;
	}
	
	printf("%d\n",int(res*res) ) ;


    return 0 ;
}
