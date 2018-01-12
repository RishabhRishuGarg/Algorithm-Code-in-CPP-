//https://www.hackerrank.com/challenges/sam-and-substrings
#include<bits/stdc++.h>
using namespace std;
#define divid 1000000007
unsigned long long int strlen(char *number)
{
	unsigned long long int i=0;
	while(number[i]!='\0') {i++;}
	return i; 
}
long long  int substrings(char *number,unsigned long long int n)
{
	//unsigned long long int total=0;
	/*
	example 1234
	have 1,2,3,4,12,23,34,123,234,1234
	so 
	digit	thousand	hundred		tens	unit	result
	
	1		1			1			1		1		1*1*1111
			
	2					2			2		2		2*2*222
	
	3								3		3		3*3*33
			
	4										4		4*4*4

	so now any number can be represent in block form like 
	for example 1234 can be expressed as 1000+200+30+4
	so now 1+2+3+4+10+2+20+3+30+4+100+20+3+200+30+4+1000+200+30+4
	=> 1*(1000+100+10+1)+(2*(200+20+2))+ (3*(30+3))+ 4*4
	
	=> 1*1111+2*222+3*333+4*4
	*/
	long long int res = 0;
	long long int f = 1;
	for(int i = n-1; i >= 0; i--) 
	{
		res = (res + (number[i]-'0')*f*(i+1)) % divid;
   		f = (f*10+1) % divid;
		
	}
	return res;
}
int main()
{
	char number[2000000];
	scanf("%s",number);
	unsigned long long int len=strlen(number);
	printf("%llu\n",substrings(number,len));

}