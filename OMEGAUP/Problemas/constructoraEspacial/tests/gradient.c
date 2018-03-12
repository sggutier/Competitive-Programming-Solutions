
/*
 * CTU Open Contest 2014
 * Problem solution: Kolonie
 *
 * Solution from the 1996 contest.
 */

#include <stdio.h>
#include <stdlib.h>
 
int p, t, fd, fp, i ,j, po ,pp, max;
 
typedef struct{ int oken, pocet; } blabla;
 
blabla vstup[1001];
 
int x[100001];
int y[100001];
 
int vokna()
{
   int res,s,i,j,xx,yy;
 
   scanf("%d", &s);
 
   scanf("%d%d", &x[0], &y[0]);
 
   res=6;
 
   for(i=1; i<s; i++)
   {
     scanf("%d%d", &xx, &yy);
     res += 6;
     for(j=0; j<i; j++)
     {
     	if((xx+1 == x[j]) && (yy == y[j])) res-=2;
     	if((xx-1 == x[j]) && (yy == y[j])) res-=2;
     	if((xx == x[j]) && (yy+1 == y[j])) res-=2;
     	if((xx == x[j]) && (yy-1 == y[j])) res-=2;        
     	if((xx+1 == x[j]) && (yy-1 == y[j])) res-=2;       
     	if((xx-1 == x[j]) && (yy+1 == y[j])) res-=2;
     }
		x[i]=xx; y[i]=yy;
	}              
 
	return res;
}
 
int porovn(const void *a, const void *b) {
  return ((blabla*)b)->oken - ((blabla*)a)->oken;
}
 
int main() {
  int n,i;
  //scanf("%d",&n);
  n = 1 ;
  while(n--) {
    scanf("%d %d", &p, &t);
 
    for(i=0; i<t; i++) {
      scanf("%d", &(vstup[i].pocet));
      vstup[i].oken=vokna();
    }
 
   /* vstup je v pocty, t, p */
 
   qsort(vstup,t,sizeof(vstup[0]),porovn);
 
   fd = vstup[0].pocet * (vstup[0].oken - 2) + 2;
   fp = vstup[0].pocet;
   for(i = 1; (i<t) && (fd <= p); i++){
      fd += vstup[i].pocet * (vstup[i].oken - 2);
      fp += vstup[i].pocet;   
   }
 
   if(fd < p)printf("The capacity of the base is only %d aliens.\n",fd);
   else {
      fp -= (fd-p) / (vstup[i-1].oken - 2);
      printf("It should be %d total.\n",fp);
   }
 
  } 
  return 0;
}

