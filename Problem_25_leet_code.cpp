//link:- https://leetcode.com/problems/reverse-nodes-in-k-group/description/
/*
	Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//link:- https://leetcode.com/problems/reverse-nodes-in-k-group/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*

	SOLUTION:-

		Main idea to reverse this is reverse logic:
			Reverse logic :- 
				* we are reversing the linked list by taking a new empty linked list
				* Traverse the given linked list
				* while traversing the given list Add node to the new list
				* The addition of list will be done at the begining of the list 
			We are applying the reverse logic group by group

			-> First find the size of list
			-> Find number of groups Groups=Size/k
			-> Apply reverse logic at every group by taking care of connecting groups to each other
			-> Append remaining list to resultant list
*/
class Solution 
{
	ListNode *root;
public:
	Solution()
	{
		root=NULL;
	}
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
    	int size=0;
        if(head==NULL) return head; // Base condition if list is empty
        if(k==1) return head; // No need to reverse the node for k==1 list will be same
    	ListNode *temp=head,*aux,*temp2;
    	while(temp) // Compute the size
    	{
    		size++;
    		temp=temp->next;
    	}    
    	int groups=size/k; // Finding how many group will be made
        if(groups==0) return head; // if no groups are there no need to process more 
    	temp=head;
    	temp2=root; // Pointer to resultant list 
    	while(groups--)
    	{
    		for(int i=0;i<k;i++)
    		{
    			aux=temp->next;
    			if(temp2==root) // at first the pointer to resultant list will be NULL all operation will be done directly to root node
    			{
    				
    				temp->next=root;
    				root=temp;
    				temp2=root;
    			}
    			else
    			{

    				temp->next=temp2->next; // Adding new node to the end of last group and begining of new group
    				temp2->next=temp;
    			}
    			temp=aux;
    			
    		}
            ListNode *prev=temp2;
    		while(temp2) // taking the pointer to resultant list to end of new group so that next group can be added
    		{
    			prev=temp2;
    			temp2=temp2->next;
    		}
    		temp2=prev;
        }
        while(temp2->next)
            temp2=temp2->next;
        temp2->next=temp; // connecting the remaining list
        return root;
    }
};