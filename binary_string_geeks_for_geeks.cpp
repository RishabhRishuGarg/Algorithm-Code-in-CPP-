//link to problem:- https://practice.geeksforgeeks.org/problems/binary-string/0
#include<bits/stdc++.h>
using namespace std;
int binary_string(char *data,int n)
{
	int *dp=new int[n];
	int total=0;
	dp[n-1]=0;
	for(int i=n-2;i>=0;i--) // this loop calculate the number of trailing one to every number
	{
		if(data[i+1]=='1')
			dp[i]=dp[i+1]+1;
		else
			dp[i]=dp[i+1];
	}
	for(int i=0;i<n;i++) // it will calculate the total permutation of possible strings
	{
		total+=(dp[i]*(data[i]-'0'));
	}
	return total;
}
int main()
{
	int t;
	int n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		char data[n];
		scanf("%s",data);
		printf("%d\n",binary_string(data,n) );
	}
}