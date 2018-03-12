#include <algorithm>
#include <cstdio>
#include <algorithm>
using namespace std ;
#define lim 1005
#define inf 1000000000

int N ;
int arr[lim] ;
int DP[lim][lim] ;
int tip[lim][lim] ;

int main() {
   int i, j ;
   
   scanf("%d",&N ) ;
   for( i=0; i<N; i++ ) 
      scanf("%d",&arr[i] ) ;
      
   arr[N] = 0 ;
   for( i=0; i<N; i++ ) { 
      DP[i][N] = arr[i] ;
      tip[i][N] = 1 ;
   }
   for( i=0; i<N; i++ ) {
      DP[i][N-1] = max( arr[i], arr[N-1] ) ;
      tip[i][N-1] = 1 ;
   }
   for( i=N-3; i>=0; i-- ) {
      for( j=N-2; j>i; j-- ) {
         DP[i][j] = inf ;
         if(    DP[i][j]  > DP[i  ][j+2]  +  max( arr[j], arr[j+1] )     )  {
            tip[i][j] = 0 ;
            DP[i][j] = DP[i  ][j+2]  +  max( arr[j], arr[j+1] )    ;
         }
         if(  DP[i][j]   > DP[j+1][j+2]  +  max( arr[i], arr[j  ] )      )  {
            tip[i][j] = 1 ;
            DP[i][j] = DP[j+1][j+2]  +  max( arr[i], arr[j  ] )    ;
         }
         if(  DP[i][j]   > DP[j  ][j+2]  +  max( arr[i], arr[j+1] )      )  {
            tip[i][j] = 2 ;
            DP[i][j] = DP[j  ][j+2]  +  max( arr[i], arr[j+1] )    ;
         }
      }
   }
   
   printf("%d\n",DP[0][1] ) ;
   for(  i = 0, j = 1 ;  i<N;  )   {
      if(  tip[i][j] == 0  )  {
         printf("%d %d\n", j+1, j+2 ) ;
         i = i ;
         j = j+2 ;
      }
      else if(  tip[i][j] == 1  )  {
         printf("%d", i+1 ) ;
         if( j!=N )
            printf(" %d",j+1 ) ;
         printf("\n");
         i = j+1 ;
         j = j+2 ;
      }
      else {
         printf("%d %d\n", i+1, j+2 ) ;
         i = j ;
         j = j+2 ;
      }
   }
   
   return 0 ;
}
