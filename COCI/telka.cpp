#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std ;
#define lim 86400

int N, Q ;

void A()  {
	int i, j ;
	int carg[lim] ;
	int A, B ;
	int x, y, z ;
	char tmp[10] ;
	long double K ;
	
	memset(  carg,  0,  sizeof(carg)   ) ;
	
	for( i=0; i<N; i++  )  {
		scanf("%d:%d:%d",&x,&y,&z ) ;
		A = z + 60*y + 60*60*x  ;
		scanf("%s",tmp ) ;
		scanf("%d:%d:%d",&x,&y,&z ) ;
		B = z + 60*y + 60*60*x  ;
		if( A<=B )  {
			for( j=A; j<=B; j++ )
				carg[j] ++ ;
		}
		else {
			for( j=A; j<lim; j++ )
				carg[j] ++ ;
			for( j=0; j<=B; j++ )
				carg[j] ++ ;
		}
	}
	
	for( i=1; i<lim; i++ )
		carg[i] += carg[i-1] ;
	
	scanf("%d",&Q ) ;
	for( ; Q; Q-- )  {
		scanf("%d:%d:%d",&x,&y,&z ) ;
		A = z + 60*y + 60*60*x  ;
		scanf("%s",tmp ) ;
		scanf("%d:%d:%d",&x,&y,&z ) ;
		B = z + 60*y + 60*60*x  ;
		if( A<=B )  {
			K = carg[B] ;
			if( A )
				K -= carg[A-1] ;
			printf("%0.9lf\n", double (  (K*1.0) / (B-A+1)   )   )  ;
		}
		else {
			K = carg[lim-1] ;
			if( A )
				K -= carg[A-1] ;
			K += carg[B] ;
			printf("%0.9lf\n",  double( (K*1.0) / (B-A+1+lim)  ) )  ;
		}
	}
}



void B()  {
	int i, j ;
	int ini[200000], fin[200000] ;
	int A, B ;
	int x, y, z ;
	char tmp[10] ;
	int W = 0,  Q ;
	long double K ;
	
	for( i=0; i<N; i++  )  {
		scanf("%d:%d:%d",&x,&y,&z ) ;
		A = z + 60*y + 60*60*x  ;
		scanf("%s",tmp ) ;
		scanf("%d:%d:%d",&x,&y,&z ) ;
		B = z + 60*y + 60*60*x  ;
		if( A<=B )  {
			ini[W] = A ;
			fin[W] = B ;
			W ++ ;
		}
		else {
			ini[W] = A ;
			fin[W] = lim-1 ;
			W ++ ;
			ini[W] = 0 ;
			fin[W] = B ;
			W ++ ;
		}
	}
	
	
	scanf("%d",&Q ) ;
	for( ; Q; Q-- )  {
		scanf("%d:%d:%d",&x,&y,&z ) ;
		A = z + 60*y + 60*60*x  ;
		scanf("%s",tmp ) ;
		scanf("%d:%d:%d",&x,&y,&z ) ;
		B = z + 60*y + 60*60*x  ;
		if( A<=B )  {
			K = 0*1.0 ;
			for( i=0; i<W;  i++  )  {
				if( fin[i]<A  ||  ini[i]>B  )   
					continue ;
				K +=  min(  B,  fin[i]  )  -  max(  A,  ini[i]  )  +1 ;
			}
			printf("%0.9lf\n", double (  (K*1.0) / (B-A+1)   )   )  ;
		}
		else {
			K = 0*1.0 ;
			for( i=0; i<W;  i++  )  {
				if( fin[i]<A  )   
					continue ;
				K += fin[i] - max(  A,  ini[i]  ) +1 ;
			}
			for( i=0; i<W;  i++  )  {
				if( ini[i]>B  )   
					continue ;
				K += min(  B,  fin[i]  )  -  ini[i]  +1 ;
			}
			printf("%0.9lf\n",  double( (K*1.0) / (B-A+1+lim)  ) )  ;
		}
	}
}



int main() {
	scanf("%d",&N ) ;
	if( N<=500  )  
		A() ;
	else
		B() ;
	return 0 ;
}
