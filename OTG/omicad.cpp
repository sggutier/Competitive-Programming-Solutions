#include <stdio.h>

int x[65536];
int y[65536];
int arr[50000][4];


int main()
{
	int n, i, j=0;
	for(i=0; i<65536; i++)
	{
		x[i]=0;
		y[i]=0;
	}
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i][0]);
		scanf("%d",&arr[i][1]);
		scanf("%d",&arr[i][2]);
		scanf("%d",&arr[i][3]);
		x[arr[i][0]]++;
		x[arr[i][2]]--;
		y[arr[i][1]]++;
		y[arr[i][3]]--;
	}
	for(i=1; i<65536; i++)
	{
		x[i]+=x[i-1];
		y[i]+=y[i-1];
	}
	for(i=0; i<n; i++)
	{
		j+=x[arr[i][0]]*(arr[i][2]-arr[i][0])*(arr[i][3]-arr[i][1]);
	}
	printf("%d\n",j);
	return 0;
}
