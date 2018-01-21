#include <bits/stdc++.h>
using namespace std;
int maximum(int x,int y)
{
	if(x>y) return x; return y;
}
int longest_palindrome_string(char *stri,int x,int y,int **dp)
{
	if(x>y) return 0; // base case if(string length is zero)
	if(x==y) return 1; // base case if string length is 1 
	if(dp[x][y]>0) return dp[x][y]; // checking if it is already executed or not
	if(stri[x]==stri[y]) // condition if both character are equal or not
	{					// if equal then cal for next two character and add 2 to length of
						//palindromic string
		dp[x][y]=2+longest_palindrome_string(stri,x+1,y-1,dp);
		return dp[x][y];
	}
	dp[x][y]=maximum(longest_palindrome_string(stri,x+1,y,dp) //calling for next x with same y
					,longest_palindrome_string(stri,x,y-1,dp));// calling for next y(y-1) with same x
	return dp[x][y];
}
int main()
{
	int t;
	char stri[1001];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",stri);
		int length=strlen(stri);
		int **dp=new int*[length+1];
		for(int j=0;j<=length;j++)
			dp[j]=new int[length+1];
		for(int j=0;j<=length;j++)
			for(int k=0;k<=length;k++)
				dp[j][k]=0;
		printf("%d\n",longest_palindrome_string(stri,0,length-1,dp));
		for(int j=0;j<length;j++)
			delete[] dp[j];
		delete dp;
	}
}