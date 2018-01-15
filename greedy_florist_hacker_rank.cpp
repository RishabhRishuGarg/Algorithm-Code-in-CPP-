//link to problem is :- https://www.hackerrank.com/challenges/greedy-florist
#include<bits/stdc++.h>
using namespace std;
unsigned long long int greedy_florist(unsigned int n,unsigned int k,int* cost)
{
	unsigned long long int result;
	int xyz=0; // xyz track on number of flower purchased by the persons.
	for(int i=n-1;i>=0;xyz++)
	{
		for(int j=0; j<k&&i>=0; j++,i--) // assign the flower[i] to every friend one by one from maximum to minimum cost.
			result=result+((xyz+1)*cost[i]); 
	}
	return result;
}
int main()
{
	unsigned int n,k;
	scanf("%u%u",&n,&k);
	int *cost= new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&cost[i]);
	}
	sort(cost,cost+n);//sorting cost in increasing order.
	printf("%llu",greedy_florist(n,k,cost));

}