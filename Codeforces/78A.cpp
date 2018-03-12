#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int main() {
	char S[1000] ;
	int i, j ;
	int res ;
	int W[] = { 5, 7, 5 } ;
	
	for( j=0; j<3; j++ )  {
		gets(S) ;
		res = 0 ;
		for(  i = strlen(S)-1; i>=0; i--  )  
			if( S[i]=='a' ||  S[i]=='i'  || S[i]=='u'  ||  S[i]=='e'  ||  S[i]=='o' )
				res ++ ;
		if(  res!=W[j]   )  {
			printf("NO\n");
			return 0 ;
		}
	}
	
	printf("YES\n");
	
	return 0 ;
}
