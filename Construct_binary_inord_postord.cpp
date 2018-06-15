//link:-https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
 Problem :-
 
 * Construct a binary tree using its Inorder  and Postorder Traversal

 Step 1:- create the end element of postorder as root 
 Step 2:- Find that element into inorder traversal
 Step 3:- Left Subarray of that index(found in step 2) will be left subtree of assigned root in step1
 			and right Subarray of that index will be right subtree if root i step1
 Step 4:- Create the right subtree same as above 3 step (make a recursive call with right subarray of inorder 
 			and decrease postorder index by 1)
 Step 5:- Create the left subtree same as above 3 step (make a recursive call with  left subarray of inorder 
 			and decrease postorder index by 1)
 			
 We are creating right subtree first has a logical reason
 	Because in our solution we have postorder traversal that mean the root will always be on end of postorder traversal
 	and we are decresing the postorder index by 1 because root of right subtree will be the left element of previous
 	postorder index			

*/
class Solution 
{ 
	inline int search(vector<int> v,int value,int i,int j)
	{
		while(i<=j)
        {
			if(v[i]==value) 
                return i;
            i++;
        }
	}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
    	int n=postorder.size()-1;
    	return AuxBuildTree(0,inorder.size()-1,0,n,inorder,postorder);
    }

    TreeNode* AuxBuildTree(int ini,int inj,int posti,int &postj,vector<int> &in,std::vector<int> &post)
    {
      
        
    	if(ini>inj) // base condition
        {
            postj++;
            return NULL;
        }
    	if(ini==inj) //base condition
    	{
    		TreeNode* temp= new TreeNode(in[ini]);
    		return temp;
    	}
    	TreeNode* root=new TreeNode(post[postj]);
    	int i=search(in,post[postj],ini,inj); // Searching for root in inorder traversal
        postj--;
    	root->right=AuxBuildTree(i+1,inj,posti,postj,in,post); //Building right subtree
        postj--;
    	root->left=AuxBuildTree(ini,i-1,posti,postj,in,post); // Building left subtree
    	return root;
    }
};