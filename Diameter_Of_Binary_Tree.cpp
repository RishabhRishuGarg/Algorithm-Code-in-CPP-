//link:- https://leetcode.com/problems/diameter-of-binary-tree/description/
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
 	int diameterOfBinaryTree(TreeNode* root) // Wrapper for function because here we need to find the maximum path from whole tree 
 	{
    	int maxi=0;
    	auxdiameterOfBinaryTree(root,maxi);
    	return maxi;
    }    
    int auxdiameterOfBinaryTree(TreeNode* root,int &maxi) 
    {
        
    	if(root==NULL) return 0;	
    	if(root->left == NULL && root->right == NULL) return 1; // Base case leaf node    
    	int ls=auxdiameterOfBinaryTree(root->left,maxi);	// Finding the solution from left subtree
    	int rs=auxdiameterOfBinaryTree(root->right,maxi);	// Finding the solution from right subtree
    	if(ls+rs>maxi) // Checking that the path we have calculated is maximum from previous calculated path or not
    		maxi=ls+rs;
    	return max(ls,rs)+1;	// returning maximum from both answers    
    }
};