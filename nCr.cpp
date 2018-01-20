#include<bits/stdc++.h>
using namespace std;
#define modu 1000000007
int ncr(int n,int r,int **dp)
{
	if(n<r) return 0;
	if(r==0 || n==r ) return 1;
	if(dp[n][r]>0) return dp[n][r];

	dp[n][r]=(ncr(n-1,r-1,dp)+ncr(n-1,r,dp))%modu;
	/*
		in this first call is for if from n item we select the nth item then further we have to
		solve our problem for only n-1 and r-1
		but in second recursive call we have not selected nth item
		so we have to solve the problem for n-1 and r;
	*/
	
	return dp[n][r];

}
int main()
{
	int t;
	unsigned long long int n,r;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%llu%llu",&n,&r);
		int **dp= new int*[n+1];
		for(int j=0;j<=n;j++)
			dp[j]=new int[r+1];
		for(int j=0;j<=n;j++)
			for(int k=0;k<=r;k++)
				dp[n][r]=0;
		
		printf("%d\n",ncr(n,r,dp));
	}
}