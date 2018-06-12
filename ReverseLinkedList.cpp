//link:-
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
      int val;
      ListNode *next;
};
class Solution {
    ListNode *root;
public:
    Solution()
    {
        root=NULL;
    }
    void AddNode(ListNode *temp)
    {
        temp->next=root;
        root=temp;
    }	
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *temp=head,*aux;
        while(temp)
        {
            aux=temp->next;
            AddNode(temp);
            temp=aux;
        }
    }
    ListNode* reverseList(ListNode* head) 
    {
    	if(head==NULL) return head;
  		ListNode *prev=head;
    	ListNode *temp=head;
    	ListNode *temp2=NULL;
    	do
    	{
    		temp=temp->next;
    		prev->next=temp2;
    		temp2=prev;
    		prev=temp;
    	}while(temp!=NULL);
    	head=temp2;
 		return head;       
    }

};

int main()
{
	return 0;
}