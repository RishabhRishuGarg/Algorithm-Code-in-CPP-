// Link to problem is https://www.hackerrank.com/challenges/recursive-digit-sum/problem
#include<bits/stdc++.h>
using namespace std;
int recursive(unsigned long long int number)
{
	if(number/10==0)
		return number;
	unsigned long long int x=0;
	while(number)
	{
		x=x+number%10;   //Extracting the digits and adding up to new number.
		number=number/10;
		
	}
	return(recursive(x));
}
int main()
{
	char ch;
	int p;

	unsigned long long int result=0;
	while((ch=getchar())!=' ')
	{
		result=result+ch-'0'; // input number is very long so at the time of inputing the number the 
							// the sum of digit is calculated.
	}

	scanf("%d",&p);
	printf("%d\n",recursive(result*p));
}