/*
 * CTU Open Contest 2012
 *
 * Sample solution: Spider
 * Author: Josef Cibulka
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAXN 4000
#define MAXM 1000000
#define MAXW 100000
 
typedef struct Edge
{
	int a,b,w; // the pair of vertices and weight
	int intree;
} Edge;
 
 
int n,m; // number of vertices and edges
Edge ed[MAXM]; // edges
 
int treew, treesize; // total weight of MST and the number of its vertices
 
// -1 for pairs (i,j) of vertices in different components, 
// otherwise max. weight on the MST-path between i and j
int replw[MAXN][MAXN];
 
 
// sort edges by weight
int edge_cmp(const void *e1, const void *e2) 
{
	return ((const Edge *)e1)->w - ((const Edge *)e2)->w;
}
 
 
// components of the two vertices of the edge being added to the tree
int ca[MAXN]; 
int cb[MAXN];
int cacnt, cbcnt;
int result;
 
int main(void)
{
	int ii,i,j,tmpa,tmpb,tmpw;
	int ci,cj;
 
	while(		scanf(" %d %d ", &n, &m) != EOF )
	{
		if(n<0 || m<0) 
			return 0;
		for(i=0;i<m;i++)
		{
			scanf(" %d %d %d ", &(ed[i].a), &(ed[i].b), &(ed[i].w));
			ed[i].a--;
			ed[i].b--;
			ed[i].intree = 0;
		}
		qsort(ed,m,sizeof(ed[0]),edge_cmp);
 
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				replw[i][j] = -1;
		for(i=0;i<n;i++)
			replw[i][i] = 0;
 
		treesize = 0;
		treew = 0;
 
		// find minimum spanning tree by Kruskal's algorithm (in quadratic time)
		// at the same time, calculate replw
		for(ii=0;ii<m;ii++)
		{
			// consider the edge ed[ii]
			tmpa = ed[ii].a;
			tmpb = ed[ii].b;
			tmpw = ed[ii].w;
			if(replw[tmpa][tmpb] != -1) 
				continue; // they are in the same component
 
			ed[ii].intree=1;
 
			cacnt = cbcnt = 0;
			for(i=0;i<n;i++) // determine vertices of components of tmpa and tmpb
			{
				assert(replw[i][tmpa] == -1 || replw[i][tmpb] == -1);
				if(replw[i][tmpa] != -1) 
					ca[cacnt++] = i;
				if(replw[i][tmpb] != -1) 
					cb[cbcnt++] = i;
			}
 
			for(i=0;i<cacnt;i++)
				for(j=0;j<cbcnt;j++)
				{
					ci = ca[i];
					cj = cb[j];
					if(ci!=cj)
						replw[cj][ci] = replw[ci][cj] = MAX(replw[ci][tmpa],MAX(tmpw,replw[cj][tmpb]));
				}
 
			treew += tmpw;
			treesize++;
 
			if(treesize == n-1) 
				break;
		}
		//		printf("%d %d\n", treesize, treew);
		if(treesize < n-1)
		{
			printf("disconnected\n");
			continue;
		}
 
		result = treew;
		for(i=0;i<m;i++) // try i as the special edge
		{
			tmpw = treew-ed[i].w-replw[ed[i].a][ed[i].b];
			if(tmpw<result)
			{
				result = tmpw;
			}
		}
		printf("%d\n", result);
	}

	return 0 ;
}

