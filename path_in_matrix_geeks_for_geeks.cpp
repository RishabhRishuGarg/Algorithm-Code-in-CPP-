//Link to problem :- https://practice.geeksforgeeks.org/problems/path-in-matrix/0
#include<bits/stdc++.h>
using namespace std;
/*
In this solution i used DP 
first i had stored all the value from first row to last row for 0th column then iterating for 
1th column . while checking for 1th there is a condition which is for checking of maximum 
of new and old 
if new value is bigger the only it will goto further steps othert wise it will return for 
next step

example
1
3
1 2 3 4 5 6 7 8 9

after iterating 0th column matrix is like:
 
 1  0  0 
 5  6  0
 12 14 15

 after intering for 1th column

 1  2  0
 6  7  8
 13 15 16

 after iterating for 2th column

 1  2  3
 4  8  9
 15 16 18

from last row 18 is maximum so 18 is answer
*/
int path_in_matrix(int **matrix,int **dp,int i,int j,int prev_i,int prev_j,int n)
{
	if(dp[i][j]<dp[prev_i][prev_j]+matrix[i][j])
		dp[i][j]=dp[prev_i][prev_j]+matrix[i][j];
	else
		return dp[n][n];
	if(i==n)
		return dp[i][j];
	if(j==n)
	{
		path_in_matrix(matrix,dp,i+1,j,i,j,n);
		path_in_matrix(matrix,dp,i+1,j-1,i,j,n);
	}
	else
		if(j==0)
		{
			
			path_in_matrix(matrix,dp,i+1,j,i,j,n);
			path_in_matrix(matrix,dp,i+1,j+1,i,j,n);
		}
		else
		{
			path_in_matrix(matrix,dp,i+1,j,i,j,n);
			path_in_matrix(matrix,dp,i+1,j-1,i,j,n);
			path_in_matrix(matrix,dp,i+1,j+1,i,j,n);
		}
	return dp[n][n];
}
void path(int **matrix,int **dp,int n)
{
	for(int i=0;i<n;i++)
	{
		path_in_matrix(matrix,dp,0,i,0,i,n-1);
	}
}
int main()
{
	int t;
	int n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		int **matrix=new int*[n];
		int **dp = new int*[n];
		for(int j=0;j<n;j++)
		{
			matrix[j]=new int[n];
			dp[j]=new int[n];
		}
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			{
				scanf("%d",&matrix[j][k]);
				dp[j][k]=0;
			}
			path(matrix,dp,n);
			int max=0;
			for(int j=0;j<n;j++)
				if(dp[n-1][j]>max)
					max=dp[n-1][j];
		printf("%d\n",max);
	}
}