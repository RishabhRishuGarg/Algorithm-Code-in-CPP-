//link:- https://leetcode.com/problems/spiral-matrix/description/
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {   
        
		int count=0,round=0,m=matrix.size();
        if(m<=0) return {} ;
        int n=matrix[0].size();
        cout<<m<<n;
		std::vector<int> v;
		while(count<m*n)
		{
			for (int i = round; i < n-round; ++i) // For upper rows
			{
				v.push_back(matrix[round][i]);
				count++;
				if(count==m*n) return v;
               
			}
            for(int i=round+1;i<m-round;i++) // For right Column
            {
                v.push_back(matrix[i][n-round-1]);
                    count++;
                if(count==m*n) return v;
                
            }
            for(int i=n-round-2;i>=round;i--) //For lower columns
            {
             	v.push_back(matrix[m-round-1][i]);
             	count++;
                if(count==m*n) return v;
            }
            for(int i=m-round-2;i>round;i--) // For left rows
            {
             	v.push_back(matrix[i][round]);
             	count++;
                if(count==m*n) return v;
            }
            round++;
		}        
    }
};
int main()
{
	int x;
	int n,m;
	cin>>m>>n;
	std::vector<std::vector<int> > v(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>v[i][j];
		}
	}


}