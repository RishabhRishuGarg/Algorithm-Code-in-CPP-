//link to problem:- https://practice.geeksforgeeks.org/problems/palindromic-array/0
#include<bits/stdc++.h>
using namespace std;
int palindrom(int *data,int n)
{
	int total=0,i=0,j=n-1;
	for(;i<j;)
	{
		//printf("%d   %d\n",i,j);
		if(data[i]==data[j]) 
		{
			i++;
			j--;
			continue;
		}
		else
			if(data[i]<data[j])
			{
				if(i+1<=j)
				{
					total++;
					data[i+1]=data[i]+data[i+1];
					i++;
				}
			}
			else
				if(j-1>=i)
				{
					total++;
					data[j-1]=data[j]+data[j-1];
					j--;
				}
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
		int *data=new int[n];
		for(int j=0;j<n;j++)
		{
			scanf("%d",&data[j]);
		}
		printf("%d\n",palindrom(data,n));
	}
}