//link:- https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//In this solution we are just reducing a big problem into two subproblem 
	// we first asking from left subtree what is longest path from you to leaf
	// then again same from right
	// and this process is running several time until the base case
	// and every call is returning the longest path from itself to leaf
	// TC :- O(n) SC:- O(height of the tree)   
    int maxDepth1(TreeNode* root)  // Recurssive  solution to find the longest path from root to any leaf node
    {
    	if(root==NULL) return 0;	
    	if(root->left == NULL && root->right == NULL) return 1; // Base case leaf node    
    	int ls=maxDepth(root->left);	// Finding the solution from left subtree
    	int rs=maxDepth(root->right);	// Finding the solution from right subtree
    	return max(ls,rs)+1;	// returning maximum from both answers
    }

    // In this solution we are traversing the tree level by level
    // largest possible level is our solution
    // we are traversing every level using a Data Structure Queue
    // every time we are pushing the left and right node of current node into queue
    // for the detection of end or start of level we are pushing a dummy node 
    // AT first after pushing the root node we pushed a dummy node also 
    // Because at root level their will be only one node and this will be end of the level
    // while traversing any time if we face any dummy node that mean a level is ended so we can increase our level counter
    // One more thing is each time when we face any dummy node it mean all child node of next level is 
    // already pushed into queue . so for next level we will again push the dummy node 
    int maxDepth(TreeNode* root) 
    {
    	
        if(root==NULL) return 0;	//Check if tree is empty or not
    	queue<TreeNode* > white;
    	white.push(root); // Initialization of queue
    	white.push(NULL); // Inserting the Dummy node
    	int count=0;
    	while(!white.empty())
    	{
    		TreeNode *current=white.front();
    		white.pop();
    		if(current==NULL) // At last level end of level will contain empty queue
    		{
    			count++; // Increasing count because we have reached at the end of levelS
    			if(white.empty())
    				break;
    			white.push(NULL);
                current=white.front();
                white.pop();
    		}
    		if(current->left!=NULL) // Inserting the left node of current node
    			white.push(current->left);
    		if(current->right!=NULL) // Inserting the right node of current node
    			white.push(current->right);
    	}
    	return count; 
    }
};