//https://practice.geeksforgeeks.org/problems/similar-expressions/0
#include<bits/stdc++.h>
using namespace std;
int remove_bracke(string &str,int n,int i,char oper) // This function removes all the brackets
{												// and set the operators accordingly.
	for(;str[i]!='\0';i++)
	{
		switch(str[i])
		{
			case '(':
					 {
					 	str.erase(str.begin()+i);
					 	if(str[i-1]=='+' || str[i-1]=='-')
							i=remove_bracke(str,n,i,str[i-1]);
						else
							i=remove_bracke(str,n,i,oper);

						break;
					 }
			case ')':
					 {
					 	str.erase(str.begin()+i);
					 	return i-1;
					 }
			case '-':
					 {
					 	if(oper=='-') str[i]='+';
					 	break;
					 }
			case '+':
					{
						if(oper=='-') str[i]='-';
						break;
					}
		}
	}
	return i;
}
void remove_operator(string &str)// this function refines the string .
{
	for(int i=1;str[i]!='\0';i++)
	{
		if((str[i]=='+' || str[i]=='-' )&& ((str[i-1]=='+' || str[i-1]=='-')))
			str.erase(str.begin()+i-1);
	}
}
void evaluate(string &str,int *value) // this module evaluate the value of particular alphabet 
{
	for(int i=0;i<26;i++)
		value[i]=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='+' || str[i]=='-')
			continue;
		if(str[i-1]=='-')
			value[str[i]-'a']--;
		else
			value[str[i]-'a']++;
	}

}
int main()
{
	int t;
	scanf("%d",&t);
	int *x=new int[26];
	int *y=new int[26];
		
	while(t--)
	{
		string str;
		string str2;
	
		cin>>str;
		cin>>str2;
	
		int l =str.length();
		int m=str2.length();
		remove_bracke(str,l,0,'+');
		remove_bracke(str2,m,0,'+');
		
		remove_operator(str);
		remove_operator(str);
		
		evaluate(str,x);
		evaluate(str2,y);
		int flas=0;
		for(int i=0;i<26;i++)
		{
			if(x[i]!=y[i])
			{
				flas=1;
				break;
			}
		}
		if(!flas) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}