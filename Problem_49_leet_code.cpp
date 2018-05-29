//link:- https://leetcode.com/problems/group-anagrams/description/
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
	public:
    	vector<vector<string>> groupAnagrams(vector<string>& strs) 
    	{
            // In this solution the key of dictionary is sorted string through which we can easily find the anagrams are valid
            // or not 
            vector<string> copy; 
            
        	unordered_map<string,vector<string> > map; // Map is to store the key according to diffrent groups
           
            unordered_map<string,vector<string> > :: iterator itr;
        	int n=strs.size(); // Number of strings
            for(int i=0;i<n;i++)
                copy.push_back(strs[i]); //Copying the data because original vector strings will be sorted and original data            will be lost.
            cout<<n;
        	for(int i=0;i<n;i++)
        	{
        		sort(strs[i].begin(),strs[i].end()); // sorting all the strings to group the anagrams
        			map[strs[i]].push_back(copy[i]); // storing all the strings according to their groups.
    		}
    		int k=0;
    		 vector<vector<string> > ans(map.size()); // declaring the vector of size same as map size
            for(itr=map.begin();itr!=map.end();++itr) // This loop is just copying all data from map to vector 
            {
                string key=itr->first;
                int m=map[key].size();
                for(int i=0;i<m;i++)
                	ans[k].push_back(map[key][i]);
                k++;
                
            }
            return ans;
    	}
};