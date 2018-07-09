/*
link:- https://www.interviewbit.com/problems/equal/

Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2

Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)

If no solution is possible, return an empty list.


*/

bool IsValid(vector<int> v1,vector<int> v2)
{
    if(v1[0]<v2[0])
        return false;
    if(v1[0]==v2[0])
    {
        if(v1[1]<v2[1])
            return false;
        if(v1[1]==v2[1])
        {
            if(v1[2]<v2[2])
                return false;
            if(v1[2]==v2[2])
                if(v1[3]<v2[3])
                    return false;
        }
    }
    return true;
}
vector<int> Solution::equal(vector<int> &A) 
{
    unordered_map<int,vector<int> >umap;
    unordered_map<int,vector<int> >:: iterator itr;
    int n=A.size();
    //vector<vector<int>> ans;
    vector<int> ans;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if((itr=umap.find(A[i]+A[j]))!=umap.end())
            {
                vector<int >v=umap[A[i]+A[j]];
                if(v[0]!=i && v[1]!=j && v[0]<i && v[0]!=j && v[1]!=i)
                {
                    v.push_back(i);
                    v.push_back(j);
                    if(ans.empty())
                        ans=v;
                    else
                        if(IsValid(ans,v))
                            ans=v;
                }
            }
            else
            {
                vector<int> v(2);
                v[0]=i;
                v[1]=j;
                umap[A[i]+A[j]]=v;
            }
        }
       // sort(ans.begin(),ans.end());
        if(ans.size()>0)
            return ans;
        else
            return {};
    
}
