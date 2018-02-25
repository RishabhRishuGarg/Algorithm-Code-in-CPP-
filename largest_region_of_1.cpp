// link to problem is https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0

#include<bits/stdc++.h>
using namespace std;
struct i_j
{
	int i,j;
};
int main()
{
	int t;
	int m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		int a[m][n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		int dp[m][n]={0}; //0 not visited
						  // 1 into queue
						 // 2 visited
		stack<i_j*> ones; // to store the indices of a field
		i_j *temp;
		unordered_map<i_j*,bool> umap; // to store the indices of all 1's in matrix
		for(int i=0;i<m;i++) // storing all indices of 1's in map
		{	
			for(int j=0;j<n;j++)
				{
					dp[i][j]=0;
					if(a[i][j]==0) continue;
					temp=new i_j;
					temp->i=i;
					
					temp->j=j;
					umap[temp]=true;
				}
		}
		i_j *x;
		int count=0,max=0;
		while(!umap.empty()) // track on field
		{
			ones.push(umap.begin()->first);
			while(!ones.empty()) // for each field to count the length of field
			{
				x=ones.top();
				int i,j;
				i=x->i;
				j=x->j;
				ones.pop();
				if(umap.find(x)!=umap.end())
					umap.erase(umap.find(x));
				if(dp[i][j]==2) continue;
				dp[i][j]=2;
				int flag=0;
				count++;
			//	cout<<"\nprocessing for "<<i<<","<<j;
			//	cout<<endl<<"count= "<<count;
				if(i!=0 && j!=0 && a[i-1][j-1]==1 && dp[i-1][j-1]<1) // for left up diagonal
				{
					flag=1;
					dp[i-1][j-1]=1;
					temp=new i_j;
					temp->i=i-1;
					temp->j=j-1;
					ones.push(temp);
				}
				if(i!=0 && a[i-1][j]==1 && dp[i-1][j]<1) // for up
				{
					flag=1;
					dp[i-1][j]=1;
					temp=new i_j;
					temp->i=i-1;
					temp->j=j;
					ones.push(temp);
				}
				if(i!=0 && j<n-1 && a[i-1][j+1]==1 && dp[i-1][j+1]<1) //for right up diagonal
				{
					dp[i-1][j+1]=1;
					flag=1;
					temp=new i_j;
					temp->i=i-1;
					temp->j=j+1;
					ones.push(temp);
				}
				if( j<n-1 && a[i][j+1]==1 && dp[i][j+1]<1) // for right 
				{

					dp[i][j+1]=1;
					flag=1;
					temp=new i_j;
					temp->i=i;
					temp->j=j+1;
					ones.push(temp);
				}
				if(i<m-1 && j<n-1 && a[i+1][j+1]==1 && dp[i+1][j+1]<1) // for right down diognal 
				{
					dp[i+1][j+1]=1;
					flag=1;
					temp=new i_j;
					temp->i=i+1;
					temp->j=j+1;
					ones.push(temp);
				}
				if(i<m-1 && a[i+1][j]==1 && dp[i+1][j]<1) // for down
				{
					dp[i+1][j]=1;
					flag=1;
					temp=new i_j;
					temp->i=i+1;
					temp->j=j;
					ones.push(temp);
				}

				if(i<m-1 && j!=0 && a[i+1][j-1]==1 && dp[i+1][j-1]<1)// for down left diagonal
				{
					dp[i+1][j-1]=1;
					flag=1;
					temp=new i_j;
					temp->i=i+1;
					temp->j=j-1;
					ones.push(temp);
				}

				if(j!=0 && a[i][j-1]==1 && dp[i][j-1]<1) // for left 
				{
					dp[i][j-1]=1;
					flag=1;
					temp=new i_j;
					temp->i=i;
					temp->j=j-1;
					ones.push(temp);
				}
				delete x;
			}	
			if(max<count)
			{
				max=count;
				
			}
			count=0;
		}
		cout<<max<<endl;
	}
}