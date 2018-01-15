// link to problem is :- https://practice.geeksforgeeks.org/problems/count-total-set-bits/0
#include<bits/stdc++.h>
using namespace std;

int count_total_bits(int n)
{
	int total=0;
	for(int i=1;i<=n;i++)
	{
		int x=i;
		while(x)
		{
			if(x%2!=0)
				total++;
			x=x/2;
		}
	}
	return total;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",count_total_bits(n));
	}
}