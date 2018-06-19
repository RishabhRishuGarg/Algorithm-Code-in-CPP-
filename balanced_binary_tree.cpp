//link:- https://leetcode.com/problems/balanced-binary-tree/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
	Problem:-  Given a binary tree, determine if it is height-balanced.

	For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

    for solution we are just finding the computing the max length of its right subtree and left subtree
    then checking wheather their diffrences are greater than 1 or not 
    if it is that mean they are not Balance binary tree
    if no that mean they are balance binary tree upto that node
    we are doing the same work on every node to check for whole tree. 


*/
class Solution 
{
	int helper(TreeNode* root,bool &flag)
	{
		if(root==NULL) return 0;
		int left=helper(root->left,flag); // Solving for left subtree
		if(flag==0) return 0;
        int right=helper(root->right,flag);// Solving for right subtree
		if(flag==0) return 0;
        if(abs(left-right)>1) // Checking wheather their diffrence is greater than one or not
		{
			flag=0;
			return 0;
		}
		else
			return(max(left,right)+1);// returning maximum height
	}
public:
    bool isBalanced(TreeNode* root) 
    {
		if(root==NULL) return true;
		bool flag=1;
		helper(root,flag);        
        return flag;
    }
};