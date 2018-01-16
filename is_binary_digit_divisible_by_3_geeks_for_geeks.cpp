//link https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-3/0/?ref=self
//divisibility test for 3 in binary is 
// for example 27=11011
// place the + on alternate digits and then place negetive on remaining digit then apply the operation
// assigned by placing the operators
//11011 
// + - + - + 
// 1 1 0 1 1 
// 1+0+1=2
// -1-1=-2
// 2+(-2)=0
// zero is divisible by 3 so 11011 is divisible by 3
#include<bits/stdc++.h>
using namespace std;
int divisible_by_3(char *ch,int n)
{
	int first=0;
	for(int i=0;i<n;i=i+2) // calculating for the positive digits
	{
		first=first+(ch[i]-'0');
	}
	for(int i=1;i<n;i=i+2) // calculating for negetive digits by directly subtracting for last calculation
	{
		first=first-(ch[i]-'0');
	}
	if(first%3==0)
		return 1;
	else
		return 0;
}
int main()
{
	int t;
	char ch[200];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",ch);
		int j=0;
		while(ch[j]!='\0')
			j++;
		printf("%d\n",divisible_by_3(ch,j));
	}
}