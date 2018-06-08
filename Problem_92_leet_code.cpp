//link:- https://leetcode.com/problems/reverse-linked-list-ii/description/
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
class Solution {
public:
    ListNode* reverseList(ListNode* head,int iter) // Reverse the list upto given iterator 
    {
        if(head==NULL) return head;
        int i=0;
        ListNode *prev=head; 
        ListNode *temp=head;
        ListNode *temp2=NULL;
        do
        {
            temp=temp->next;
            prev->next=temp2;
            temp2=prev;
            prev=temp;
            i++;
        }while(temp!=NULL && i!=iter);
        head=temp2;
        return head;       
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) //Reverse list between two nodes or in a range;  
    {
        if(head==NULL) return head;
        ListNode *temp=head;
        int i=0;
        ListNode *alpha=NULL; // This variable is using for next node to nth node
        ListNode *alpha_start=NULL;
        while(i<n && temp) // this loop is to store the value of previous node of mth node to store the address of reversed node
        {
            if(i==m-2)
                alpha_start=temp;
            temp=temp->next;
            i++;
        }       
        alpha=temp;
        if(alpha_start==NULL) // if m is starting index then alpha start remain null
        {
            head=reverseList(head,n-m+1); // then reverse of list should start from head and should store into head
            temp=head;
            while(temp->next)
                temp=temp->next; // to reach to last node of reversed node for connecting it to next remaining node;
            temp->next=alpha; // connecting the remaining node;
        }
        else
        {
            alpha_start->next=reverseList(alpha_start->next,n-m+1);
       
            while(alpha_start->next)
            {
                alpha_start=alpha_start->next;
            }
            alpha_start->next=alpha;
        }
        return head;
    }
  
};
