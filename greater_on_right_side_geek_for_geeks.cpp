//link to problem is:- https://practice.geeksforgeeks.org/problems/greater-on-right-side/0
#include<bits/stdc++.h>
using namespace std;
void greater_on_right_side(int *data,int n)
{
	int current=data[n-1];
	data[n-1]=-1;
	for(int j=n-2;j>=0;j--)
	{
		if(data[j]<current)
			data[j]=current;
		else
			if(data[j]>current)
			{
				int temp=data[j];
				data[j]=current;
				current=temp;
			}
	}
}
int main()
{
	int n;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		int *data=new int[n];
		for(int j=0;j<n;j++)
		{
			scanf("%d",&data[j]);
		}
		greater_on_right_side(data,n);
		for(int j=0;j<n;j++)
			printf("%d ",data[j]);
		printf("\n");
	}
}