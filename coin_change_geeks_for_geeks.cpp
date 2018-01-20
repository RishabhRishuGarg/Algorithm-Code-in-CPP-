#include <bits/stdc++.h>
using namespace std;
int coin_change(int *coins,int n,int **dp,int value)
{
	//printf("called for %d %d\n",n,value);
	if(value < 0) return 0;
	if(value==0) return 1;
	if(n<=0) return 0;

	if(dp[n][value]>0) return dp[n][value];
	dp[n][value]=coin_change(coins,n,dp,value-coins[n-1])+coin_change(coins,n-1,dp,value);
	return dp[n][value];
}
int main()
{
	int t;
	int n;
	int value;
	scanf("%d",&t);
	for(int a=0;a<t;a++)
	{
		scanf("%d",&n);
		int *coins=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&coins[i]);
		scanf("%d",&value);
		//sort(coins,coins+n);
		int **dp=new int*[n+1];
		for(int i=0;i<=n;i++)
			dp[i]=new int[value+1];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=value;j++)
				dp[i][j]=0;
		printf("%d\n",coin_change(coins,n,dp,value) );
	}
}