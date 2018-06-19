//link:- https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0
#include "bits/stdc++.h"
using namespace std;
/*
	Problem :- Convert preorder traversal of a BST into Postorder traversal

	In this problem we can analys that in preorder traversal Root,left,Right scenario is maintaned
	now we have to convert it into Left,Right,Root scenario 

	Main thing is in traversal array of pre-order if we analys that for every root node value their
	will be smaller element than root value upto some distance because in pre order after root it will
	traverse it left first so that upto some distance from root their will be smaller element that root node
	using this we can find out left subtree
	And the remaining element are the greater than the root node element
	that mean remaining element will be left subtree for that root node
	now using these we can build our tree with recursive calls 

*/
bool PreToPost(vector<int> &pre,vector<int> &post,int low,int high)
{
	if(low>high) return true;
	if(low==high) // if leaf node occured
	{
		post.push_back(pre[low]);
		return true;
	}
	int index=low;
	for(int i=low+1;i<=high;i++) // Finding the left subtree ending 
	{
		if(pre[i]>pre[low])
			break;
		index++;
	}
	for (int i = index+1; i <=high; ++i)
	{
		if(pre[i]<pre[low])
			return false;
	}
	if(!PreToPost(pre,post,low+1,index)) // buliding left subtree
	    return false;
	if(!PreToPost(pre,post,index+1,high)) //buildin right subtree
	    return false;
	post.push_back(pre[low]); // push the root node 
	return true;
}
void print_array(vector<int> v)
{
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		std::vector<int> pre(n);
		for(int i=0;i<n;i++)
			cin>>pre[i];
		vector<int> post;
		if(PreToPost(pre,post,0,n-1))
			print_array(post);
		else
			printf("NO\n");
	}
}