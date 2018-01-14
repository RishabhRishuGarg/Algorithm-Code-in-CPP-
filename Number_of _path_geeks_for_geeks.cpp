// link to problem is :- https://practice.geeksforgeeks.org/problems/number-of-paths/0

#include<bits/stdc++.h>
using namespace std;
int path(int i,int j,int m,int n)
{
	if(i==m&&j==n) // termination condition if i and j reached to bottom right corner of matrix 
		return 1;
	if(i==m) // Checking wheather i is reached to last row or not if yes then find the solution for 
			//same row and next column
		return(path(i,j+1,m,n));
	if(j==n)// Checking wheather j is reached to last column or not if yes then find the solution for 
			//same column and next row
		return(path(i+1,j,m,n));
	return(path(i,j+1,m,n)+path(i+1,j,m,n)); // checking for next row + checking for next column.
}
int main()
{
	int t;
	scanf("%d",&t);
	int m,n;
	for (int i=0;i<t;i++)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",path(1,1,m,n));
	}
}