/*
 * CTU Open Contest 2011
 *
 * Sample solution: gradient
 * Author: Josef Cibulka
 */

/* Variation on the standard algorithm to find the largest rectangle 
 * filled with 1's in a (0,1)-matrix. Rectangles are shrunk to squares.
 * In solve(), len is the length of the longest constant sequence starting
 * at a given position.
 * When finding diagonal gradient, we are finding a rectangle such that
 * the difference when going to the right has the same absolute value as
 * the difference when going down. Thus, in solve45(), len is the length 
 * of the longest arithmetic progression to the right; the difference is 
 * stored in dif. 
 * The matrix is then mirrored and the same is repeated. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXN 2000
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


int m,n;
int data[MAXN][MAXN];
int dif[MAXN][MAXN];
short int len[2*MAXN][2*MAXN];

// for every i<wcnt, the rectangle with upper-left corner in the current 
// position, width width[i] and lowest row in lowest[i] is a correct rectangle, 
int wcnt;
int wlist[4*MAXN];
int lowest[4*MAXN];

int solve()
{
	int i,j,k,tmp,tmpK,nocont;
	int ret;
	int diddelete;

	for(i=0;i<m;i++) 
	{
		tmp = 1;
		for(j=n-1;j>=0;j--)
		{
			if(j==n-1 || data[i][j]!=data[i][j+1]) 
			{
				tmp = 1;
			} else tmp++;
			len[i][j] = tmp;
		}
	}
	ret = 1;
	for(j=0;j<n;j++)
	{
		wcnt = 1;
		wlist[0] = len[m-1][j];
		lowest[0] = m-1;
		tmpK = 0; // to avoid compiler warning
		for(i=m-2;i>=0;i--)
		{
			if(i<m-2 && tmpK!=(data[i][j]-data[i+1][j])) nocont = 1; else nocont = 0;
			k = wcnt-1;
			diddelete = 0;
			while(k>=0 && (nocont || len[i][j]<wlist[k]))
			{
				// compute the size of the rectangle that cannot get higher anymore
				tmp = MIN(wlist[k],(lowest[k]-i));
				tmp *= tmp;
				if(tmp>ret) ret = tmp;
				k--;
				diddelete = 1;
			}
			if(nocont)
			{
				wcnt = 0;
				if(len[i][j]>len[i+1][j]) 
				{ 
					lowest[wcnt] = i+1; wlist[wcnt] = len[i+1][j]; wcnt++;
				}
				wlist[wcnt] = len[i][j];
				if(len[i][j]<=len[i+1][j]) lowest[wcnt] = i+1; else lowest[wcnt] = i;
				wcnt++;
			}
			else
			{
				wcnt = k+1;
				if(wcnt==0 || len[i][j]>wlist[wcnt-1])
				{
					// add the new width
					if(diddelete==0) lowest[wcnt] = i;
					// else nothing ---  keep the value that was in lowest[wcnt]
					wlist[wcnt++] = len[i][j];
				}
			}			
			tmpK = data[i][j]-data[i+1][j];
		}
		// try the remaining rectangles
		for(k=0;k<wcnt;k++)
		{
			tmp = MIN(wlist[k],(lowest[k]+1));
			tmp *= tmp;
			if(tmp>ret) ret = tmp;
		}
	}	
	return ret;
}

int solve45()
{
	int i,j,k,tmp,nocont;
	int ret;
	int diddelete;
	int vdif;

	for(i=0;i<m;i++) 
	{
		tmp = 1;
		for(j=n-1;j>=0;j--)
		{
			if(j==n-1)
			{
				len[i][j] = 1;
			} else if(j==n-2 || data[i][j]-data[i][j+1] != dif[i][j+1])
			{
				len[i][j] = 2; dif[i][j] = data[i][j]-data[i][j+1];
			}
			else 
			{
				len[i][j] = len[i][j+1]+1; dif[i][j] = dif[i][j+1];
			}					
		}
	}

	ret = 1;
	for(j=0;j<n;j++)
	{
		wcnt = 1;
		wlist[0] = len[m-1][j];
		lowest[0] = m-1;
		vdif = 0; // to avoid vompiler warning
		for(i=m-2;i>=0;i--)
		{
			if(i<m-2 && vdif!=(data[i][j]-data[i+1][j])) nocont = 1; else nocont = 0;
			vdif = data[i][j]-data[i+1][j];
			if(abs(vdif) != abs(dif[i+1][j])) nocont = 1;
			if(dif[i+1][j]!=dif[i][j]) nocont = 1;
			k = wcnt-1;
			diddelete = 0;
			while(k>=0 && (nocont || len[i][j]<wlist[k]))
			{
				// compute the size of the rectangle that cannot get higher anymore
				tmp = MIN(wlist[k],(lowest[k]-i));
				tmp *= tmp;
				if(tmp>ret) ret = tmp;
				k--;
				diddelete = 1;
			}
			if(nocont)
			{
				wcnt = 0;
				if(len[i][j]>len[i+1][j] && abs(vdif)==abs(dif[i+1][j]) && dif[i+1][j] == dif[i][j]) 
				{ 
					lowest[wcnt] = i+1; wlist[wcnt++] = len[i+1][j]; 
				}
				if(len[i+1][j]>=len[i][j] && abs(vdif)==abs(dif[i+1][j]) && dif[i+1][j] == dif[i][j]) 
					lowest[wcnt] = i+1; 
				else lowest[wcnt] = i; 
				wlist[wcnt++] = len[i][j];
			}
			else
			{
				wcnt = k+1;
				if(wcnt==0 || len[i][j]>wlist[wcnt-1])
				{
					// add the new width
					if(diddelete==0) lowest[wcnt] = i;
					// else nothing ---  keep the value that was in lowest[wcnt]
					wlist[wcnt++] = len[i][j];
				}
			}			
		}
		// try the remaining rectangles
		for(k=0;k<wcnt;k++)
		{
			tmp = MIN(wlist[k],(lowest[k]+1));
			tmp *= tmp;
			if(tmp>ret) ret = tmp;
		}
	}	
	return ret;
}




int main(void)
{
	int i,j,tmp;
	int res;

	while( scanf("%d",&m)!=EOF )
	{
		n = m ;
		if(m==0 && n==0) break;
		for(i=0;i<m;i++) for(j=0;j<n;j++)
		{
			scanf(" %d ", &(data[i][j]));
			assert(data[i][j]>=0 && data[i][j]<65536);
		}

		res = solve();
		tmp = solve45();
		if(tmp>res) res = tmp; 

		// mirror - for solve45
		for(i=0;i<m;i++) for(j=0;j<n/2;j++) 
		{
			tmp = data[i][n-1-j]; data[i][n-1-j] = data[i][j]; data[i][j] = tmp;
		}
		// mirror around diagonal - for solve
		for(i=0;i<MAX(m,n);i++) for(j=0;j<i;j++) 
		{
			tmp = data[j][i]; data[j][i] = data[i][j]; data[i][j] = tmp;
		}
		tmp = m; m = n; n = tmp;
		
		tmp = solve();
		if(tmp>res) res = tmp;
		
		tmp = solve45();
		if(tmp>res) res = tmp;
		printf("%d\n", res);
	}
	return 0;
}
