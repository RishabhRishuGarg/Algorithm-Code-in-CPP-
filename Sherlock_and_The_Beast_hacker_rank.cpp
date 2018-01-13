//link to problem :- https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem
#include <bits/stdc++.h>
using namespace std;
int descent_number(long long int *n,int *m)
{	

	/*
	In this solution N represent the number of 5's and N represent the number of 3's
	at every step checking the conditions of question and setting up the N and M according to need
	*/
	if(*n%3==0&&*m%5==0) //Termination condition of recursive loop 
		return 1;	 	// condition is when ans is calculted when N is power of 3 and m is power of 5
	if(*n<3)           // termination condition when the possible result can not be calculated
		return 0;

	if((*n)%3!=0)// condition for setting up the number of 5's
	{
		*m=(*m)+((*n)%3);
		*n=(*n)-((*n)%3);
	}
		
	if((*m)%5!=0) //condition for setting up the number of 3's
	{
		*n=(*n)-(5-(*m)%5);
		*m=(*m)+(5-(*m)%5);
	}
	
	return(descent_number(n,m)); // finding the solution for next value of N and M
}
int main()
{
	int t;
	scanf("%d",&t);
	long long int n;
	for(int i=0;i<t;i++)
	{
		scanf("%llu",&n);
		int m=0;
		int x=descent_number(&n,&m);
		if(x)
		{
			for(int j=0;j<n;j++)
			{
				printf("5");
			}
			for(int j=0;j<m;j++)
			{
				printf("3");
			}
		}
		else
			printf("-1");

		printf("\n");
	}
}