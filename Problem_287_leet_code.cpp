//link :- https://leetcode.com/problems/find-the-duplicate-number/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& v) //  Time Complexity :-O( NLOG(N) ) SC :- O(1)
    {
        int x=0,n=v.size();
        sort(v.begin(),v.end());
    	for(int i=0;i<n-1;i++)
    	{
            if(v[i]==v[i+1]) return v[i];
    	}    
    	return x;    
    }
    int findDuplicate2(std::vector<int> v) //TC:- O(N) SC:- O(1)
    {
    	int index,n=v.size();
    	for(int i=0;i<n;i++)
    	{
    		index=v[i]%n; //doing this will increase the element by n after finding the remainder we will get the same number
    		v[index]+=n;
    	}
    	for(int i=0;i<n;i++)
    	{
    		if(v[i]/n>1) //if any number is repeated the atleast n will be added twice thats why we are checking for greater than 1 
    					 // because for every number n will be added once for sure.
    			return i;
    	}
    }
};
int main()
{
	int n;
	Solution s;
	int x;
	cin>>n;
	std::vector<int> v;
	v.reserve(n);
	while(n--)
	{
		cin>>x;
		v.push_back(x);
	}
	cout<<s.findDuplicate(v);
}