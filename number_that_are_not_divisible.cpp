//link to problem is https://practice.geeksforgeeks.org/problems/number-that-are-not-divisible/0
#include<bits/stdc++.h>
using namespace std;
/*
You will be given a positive integer N. Your task is to find the number of positive integers K ≤ N
such that K is not divisible by any number among the set {2,3,4,5,6,7,8,9,10}. 
so now a number which is divisible 2 that are also divisible by 4,6,8,10 
so we need not to check for them
and those numbrers are divisible by 3 al also divisible by 9 
so only we need to check only for 2,3,5,7 

in this solution i first checked How may number are divisible by 2,3,5,7 and then subtracted the 
resultant number from n will give the answer.
*/
unsigned long long int find_pair(unsigned long long int n)
{	unsigned long long int count=0;
	int one[4]={2,3,5,7};
	int two[6]={6,10,14,15,21,35};
	int three[4]={30,42,70,105};
	int four=210;
	for(int i=0;i<4;i++)
	{
		count=count+(n/one[i]);
	}
	for(int i=0;i<6;i++)
		count=count-(n/two[i]);
	for(int i=0;i<4;i++)
		count=count+(n/three[i]);
	count=count-(n/four);
	return count;


}

int main()
{
	int t;
	scanf("%d",&t);
	unsigned long long int n;
	for(int i=0;i<t;i++)
	{
		scanf("%llu",&n);
		unsigned long long int z=find_pair(n);
		printf("%llu",n-z);
		printf("\n");
	}
}