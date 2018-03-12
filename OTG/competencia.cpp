#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <list>
#include <queue>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
#define inf (1<<30)

int main() {
  int N, M ;
  int minP[5000] ;
  list <par>  adj[5000] ;
  priority_queue <par> Q ;
  bool usd[5000] ;
  int i, j ;
  list <par> :: iterator  it ;
  par pos, pos2 ;
  
  
  scanf("%d%d",&N,&M ) ;
  for( i=0; i<M; i++ ) {
    scanf("%d%d",&pos.s,&pos2.s  ) ;
    scanf("%d%d",&pos.f,&pos2.f  ) ;
    pos.s--, pos2.s -- ;
    adj[pos.s].push_back(  pos2  )  ;
    adj[pos2.s].push_back(  pos  )  ;
  }
  M *= 2 ;
  for( i=0; i<N; i++ )
      minP[i] = inf,  usd[i] = 0 ;
  
  minP[0] = 0 ;
  Q.push(  par(0,0)  ) ;
  while( !Q.empty()  )   {
    pos = Q.top() ;
    Q.pop() ;
    if(  usd[pos.s]  )
      continue ;
    i = pos.s ;
    j = pos.f ;
    usd[i] = 1 ;
    printf("%d %d\n", pos.s+1, pos.f  ) ;
    printf("    ");
    for( it=adj[i].begin();  it!=adj[i].end();  it++   )   {
      printf("%d ", (*it).s +1  ) ;
      if(   minP[(*it).s] >   (*it).f + j   )   {
	minP[(*it).s] =   (*it).f + j ;
	Q.push(   par(  minP[(*it).s],  (*it).s  )    )  ;
      }
    }
    cout << endl ;
  }
  
  printf("%d\n",minP[N-1]  ) ;
  
  return 0 ;
}