//link:- https://leetcode.com/problems/delete-node-in-a-bst/description/
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
	Deletion of Node in BST is very tricky

	Step 1. Find the position of node.
	Step 2. Delete the node.
	
	--> Problem :- Choose what node select to put at the place of  deleted node.

			To solve this problem we can use the in-order predecesor of that node
			If any in-order predecessor does not exist then find in-order sucessor 

			main chalange if in-order pred or in-order Succesor are leaf node then we can delete that
			node directly.
			But the new element will take place of deleted node
			now we need to check the same for new node wheather we can delete new node or not
			because new node is already copied to diffrent place
			To maintane the properties of BST we need to check same for new element 

			And we need to delete or replace the new element with its mapped element if new element
			 is now leaf  


*/
class Solution 
{
	TreeNode* findInorderPredesor(TreeNode* root)
	{
		TreeNode* temp=root->left;
        TreeNode* prev=root;
		while(temp->right)
		{	
			prev=temp;
			temp=temp->right;
		}
		return prev;
	}
	/*
		We are returning parent because if we need to delete the secessor the with the deletion process
		we need to change its parent pointer location also so that we are returning parent 
	*/
	TreeNode* findInorderSucesor(TreeNode* root) // Return the parent node of inorder sucessor of given node
	{
		TreeNode* temp=root->right;
        TreeNode* prev=root;
		while(temp->left)
		{	prev=temp;
			temp=temp->left;
		}
		return prev;
	}
	/*
		We are returning parent because if we need to delete the secessor the with the deletion process
		we need to change its parent pointer location also so that we are returning parent 
	*/
	TreeNode* FindKey( TreeNode* root,int key)
	{
		TreeNode* prev=NULL;
		while(root)
		{
           
			if(root->val==key) return prev;
			prev=root;
			if(root->val>key) root=root->left;
			else root=root->right;
		}
		return NULL;
	}
	inline bool isLeaf(TreeNode* root) // Check wheather the given node is leaf node or not
	{
		if(root->left==NULL && root->right==NULL)
			return true;
		return false;
	}
	void delete_node(TreeNode* root) // This recursive function delete the node by maintaining the Criteria 
	{
		//cout<<"Traversing for "<<root->val<<endl;
		if(root->right!=NULL) // First choice to replace the key element with its inorder sucessor 
		{
			TreeNode* succ=findInorderSucesor(root);
			if(succ==root) 
			{
				if(isLeaf(succ->right))// If inorder sucessor is leaf delete directly
				{
					root->val=succ->right->val;
					delete succ->right;
					succ->right=NULL;
					return;
				}
				else // If not leaf then delete the inorder sucessor with same process
				{	
					root->val=succ->right->val;
					delete_node(succ->right);
				}
			}
			else
			{
				root->val=succ->left->val;
				if(isLeaf(succ->left))
				{
					
					delete succ->left;
					succ->left=NULL;
					return ;
				}
				else
				{	
					
					delete_node(succ->left);
				}
			}
		}
		else
		{
			TreeNode* pred=findInorderPredesor(root);
			if(pred==root)
			{
				root->val=pred->left->val;
				if(isLeaf(pred->left))
				{
					delete pred->left;
					pred->left=NULL;
					return;
				}
				else
				{	
					//root->val=pred->left->val;
					delete_node(pred->left);
				}
			}
			else
			{
				root->val=pred->right->val;
				if(isLeaf(pred->right))
				{
					delete pred->right;
					pred->right=NULL;
					return ;
				}
				else
				{	
					//root->val=pred->right->val;
					delete_node(pred->right);
				}
			}
		}
	}
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL) return NULL;
        if(isLeaf(root)) // if tree has the only element is root
        {
        	if(root->val==key) return NULL;
        	else
        		return root;
        }
        TreeNode* prev=FindKey(root,key);
        if(prev==NULL) // if key found at root node
        {
            if(root->val!=key) // key does not found in tree
                return root;
            delete_node(root);
            return root;
        }
    //    cout<<prev->val<<endl;
        if(prev->left && prev->left->val==key) // if element exist at left child of parent node
        {
        	if(isLeaf(prev->left))
        	{
        		delete prev->left;
        		prev->left=NULL;
        		return root;
        	}
        	else
        	{
        		delete_node(prev->left);
        	}
        }
        else // if key exist at right node or parent node
        {
            
        	if(isLeaf(prev->right))
        	{
        		delete prev->right;
        		prev->right=NULL;
        		return root;
        	}
        	else
        	{
        		delete_node(prev->right);
        	}
        }
       
        return root;
    }
};