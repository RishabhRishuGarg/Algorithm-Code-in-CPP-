//link :- https://leetcode.com/problems/find-peak-element/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) // nums is input 
    {	
    	// Solution is done using binary search approach in this case for mid element we have three posibilities
    	// one is mid element at any peek point.
    	// second is mid element at right side of peek element;
    	// third is mid element at left side of peek element;
    	// by applying divide and prune thinking this problem is solved in O(logN) time complexity with constant space
    	int n=nums.size();
        int low=0,high=n-1,mid;
        while(low<high)
        {
        int n=nums.size();
        int low=0,high=n-1,mid;
   
        while(high-low>1)
        {
        	mid =low+(high-low)/2;
        	if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid]) return mid;
        	if(nums[mid-1]>nums[mid]) high=mid-1;
        	else low=mid+1;
        }
    if(nums[low]>=nums[high]) return low;
        else return high;
        }
        return mid;
        
    }
};
