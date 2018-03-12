#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <list>
using namespace std ;

int main() {
  int N ;
  list <int>  pilas[30] ;
  list <int> :: iterator  it  ;
  int i, j, tmp ;
  char S[6], S2[6] ;
  int A, B ;
  
  scanf("%d",&N ) ;
  for( i=0; i<N; i++ )
    pilas[i].push_back(i) ;
  scanf("%s",S2 ) ;
  while(  S2[0]!='q'  )  {
    scanf("%d",&A ) ;
    scanf("%s",S ) ;
    scanf("%d",&B ) ;
    
    for( i=0; i<N; i++ )  {
      for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=A;  it++  )  ;
      if( it!=pilas[i].end()  )
	break ;
    }
    j = i ;
    for( i=0; i<N; i++ )  {
      for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=B;  it++  )  ;
      if( it!=pilas[i].end()  )
	break ;
    }
    if( i==j ) {
      scanf("%s",S2 ) ;
      continue ;
    }
    
    
    if(  S2[0]=='m'  )  {
      if( S[1]=='n'  )   {
	for( i=0; i<N; i++ )  {
	  for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=A;  it++  )  ;
	  if( it!=pilas[i].end()  )
	    break ;
	}
	while(   it!=pilas[i].end()   )  {
	  if( (*it) != A  )  {
	    pilas[ *it ].push_back( *it ) ;
	  }
	  it = pilas[i].erase( it ) ;
	}
	for( i=0; i<N; i++ )  {
	  for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=B;  it++  )  ;
	  if( it!=pilas[i].end()  )
	    break ;
	}
	it ++ ;
	while(   it!=pilas[i].end()   )  {
	  pilas[ *it ].push_back( *it ) ;
	  it = pilas[i].erase( it ) ;
	}
	pilas[i].push_back( A ) ;
      }
      else  {
	for( i=0; i<N; i++ )  {
	  for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=A;  it++  )  ;
	  if( it!=pilas[i].end()  )
	    break ;
	}
	while(   it!=pilas[i].end()   )  {
	  if( (*it) != A  )
	    pilas[ *it ].push_back( *it ) ;
	  it = pilas[i].erase( it ) ;
	}
	for( i=0; i<N; i++ )  {
	  for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=B;  it++  )  ;
	  if( it!=pilas[i].end()  )
	    break ;
	}
	pilas[i].push_back( A ) ;
      }
    }
    else {
      if( S[1]=='n'  )   {
	for( i=0; i<N; i++ )  {
	  for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=B;  it++  )  ;
	  if( it!=pilas[i].end()  )
	    break ;
	}
	j = i ;
	it ++ ;
	while(   it!=pilas[i].end()   )  {
	  pilas[ *it ].push_back( *it ) ;
	  it = pilas[i].erase( it ) ;
	}
	for( i=0; i<N; i++ )  {
	  for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=A;  it++  )  ;
	  if( it!=pilas[i].end()  )
	    break ;
	}
	while(   it!=pilas[i].end()   )  {
	  pilas[ j ].push_back( *it ) ;
	  it = pilas[i].erase( it ) ;
	}
      }
      else {
	for( i=0; i<N; i++ )  {
	  for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=B;  it++  )  ;
	  if( it!=pilas[i].end()  )
	    break ;
	}
	j = i ;
	for( i=0; i<N; i++ )  {
	  for( it=pilas[i].begin();  it!=pilas[i].end()  &&  (*it)!=A;  it++  )  ;
	  if( it!=pilas[i].end()  )
	    break ;
	}
	while(   it!=pilas[i].end()   )  {
	  pilas[ j ].push_back( *it ) ;
	  it = pilas[i].erase( it ) ;
	}
      }
    }
      
    
    scanf("%s",S2 ) ;
  }
  
  for( i=0; i<N; i++ ) {
    printf("%d:",i ) ;
    for( it=pilas[i].begin();  it!=pilas[i].end();  it++  )
      printf(" %d",(*it)  ) ;
    cout << endl ;
  }
  
  return 0 ;
}