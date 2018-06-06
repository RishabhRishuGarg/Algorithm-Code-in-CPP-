// link:- https://leetcode.com/problems/palindrome-linked-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Problem:- Given a singly linked list, determine if it is a palindrome.
class Solution 
{
	ListNode* reverseList(ListNode* head) // Function will reverse the list 
    {
    	if(head==NULL) return head;
  		ListNode *prev=head;
    	ListNode *temp=head;
    	ListNode *temp2=NULL;
    	do
    	{
    		temp=temp->next; // temp will store the address ofr next node to be traverse
    		prev->next=temp2; // Temp2 will contain the address of last second previous element that need to store in current element
    		temp2=prev; // updating the temp2 with new previous 
    		prev=temp;  // updating the prev with new previous
    	}while(temp!=NULL);
    	head=temp2;
 		return head;       
    }
	public:

    bool isPalindrome1(ListNode* head) // TC :- O(N) SC:- O(N) 
    {
    	stack<int> palin;
    	ListNode *slow=head,*fast=head;
    	int size=0;
    	while(fast && fast->next )
    	{
    		//size++;
    		palin.push(slow->val); // Push half the element into stack
    		slow=slow->next;
    		fast=fast->next->next;
    	}
    	if(fast!=NULL)	// if linked list have odd number of elements then skip the current element for check;
    		slow=slow->next;
    	int x;
    	while(slow)
    	{
    		x=palin.top();	
    		palin.pop();
    		if(x!=slow->val) return false;
    		slow=slow->next; 
    	}
    	return true;
    }
   bool isPalindrome(ListNode* head) // TC :- O(N) SC :- O(1) 
    {
    	// in this solution a simple approach is applied that is reverse the half of the list then start checking
    	// from first of list and half of list if element are not equal then given list is no palindrom
    	// if all are equal the given list is palindrome
     if(head==NULL) return true;
    	ListNode *slow=head,*fast=head,*prev=NULL;
    	// Finding the middle point using two pointer approach while one pointer is fast moving(2 steps) and another is slow moving(1 step)
    	// then if fast pointer at null then slow pointer will point to middle element.
    	while(fast && fast->next ) // Finding the middle point using two pointer approach while
    	{
    		prev=slow;
    		slow=slow->next;
    		fast=fast->next->next;
    	}
    	if(fast!=NULL)	// if linked list have odd number of elements then skip the current element for check;
    	{	
    		slow->next=reverseList(slow->next); // Reversing the linked list and assinging the new pointer to list
    		slow=slow->next;
    	}
    	else
    	{
    		prev->next=reverseList(prev->next);
    		slow=prev->next;
    	}
    	fast=head;
    	while(slow && fast) // Using two pointer approach to check One pointer start from head and other starts from middle of linked list.
    	{
    		if(slow->val != fast->val)
    			return false;
            slow=slow->next;
            fast=fast->next;
    	}
    	return true;
    }
};