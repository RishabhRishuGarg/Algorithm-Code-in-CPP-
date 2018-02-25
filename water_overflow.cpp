//link to problem https://practice.geeksforgeeks.org/problems/champagne-overflow/0
#include<bits/stdc++.h>
using namespace std;
void set_pattern(float **ans,float n)
{
	// creating the pascal triangle from the logic of pascal triangle 
	//every next element to any row will be i+1,j and i+1,j+1 for i ,j and for i,j+1 element will be
	// i+1,j+1 and i+1,j+2 so i+1,j+1 is common to both as same the flow of water .
	ans[0][0]=n;
	for(int i=0;i<1001;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			if(ans[i][j]>1)
			{
				float x=ans[i][j]-1;
				ans[i][j]=1;
				ans[i+1][j]=ans[i+1][j]+(x/2);
				ans[i+1][j+1]=ans[i+1][j+1]+(x/2);
				n--;
			}

		}
	}
}
int main()
{
	int t;
	int k,l;
	float n;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>l;
		float **ans=new float*[1001];
		for(int i=0;i<1001;i++)
			ans[i]=new float[1001];
		for(int i=0;i<1001;i++)
			for(int j=0;j<1001;j++)
				ans[i][j]=0;
			set_pattern(ans,n);
		cout<<ans[k-1][l-1]<<endl;


	}
}