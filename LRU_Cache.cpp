//link:- https://leetcode.com/problems/lru-cache/description/
//This LRU Cache problem support only 2 Methods
//1. Get the element 
//2. Put the element

/*
	In this solution a composite data structure is designed using HashSet and double Linked list
	-- Linked list store the data(key,value)
	-- HashSet is used to store the address of every node as value to its key as "key"
	Every time when get method is called it first check in hashset wheather required key is available
	or not 
	# if not available then it will return -1
	# if available then it will take the address of that node at which value is stored
	then gettin the value from linked list and moving that node to end of the list

	NOTE:- Reason for moving last accesed node to end is to follow the property of Least recently used
		by doing this we are clear with one concept is the lru element will always be the first element of 
		list 
		so that whenever cache will be full we can directly delete the first node and add new element to the end
		of the list
*/
#include<bits/stdc++.h>
using namespace std;
struct node // Linked node structure
{
	int key;
	int value;
	node *prev,*next;
};
class DLinkedList //API to Doubly Linked list
{
	node *start;
	node *end;
public:
	DLinkedList() // Creating head node to list
	{
		start=NULL;
		node *temp=new node;
		temp->key=0;
		temp->value=0;
		temp->prev=NULL;
		temp->next=NULL;
		start=temp;
		end=temp;
	}
	void display() // Used to display the List
	{
		node *temp=start;
		while(temp)
		{
			cout<<"("<<temp->key<<","<<temp->value<<")->";
			temp=temp->next;
		}
	}
	node* put(int key,int data)// adding the element to end of list
	{
		node *temp=new node;
		temp->key=key;
		temp->value=data;
		temp->next=NULL;
		temp->prev=end;
		end->next=temp;
		end=temp;
        return temp;
	}
	void delete_node(node *pos) // Delete the node from given position
	{
		pos->prev->next=pos->next;
		if(pos->next==NULL) // if given position is last node already we need to change the value of end
		{
			end=pos->prev;

		}
		else
		{
			
			pos->next->prev=pos->prev;
		}
		delete pos;

	}
	int get(node *temp) // return the value of position
	{
		return temp->value;
	}
	void change(node *pos,int value) // Change the value of position
	{
		pos->value=value;
	}
	int delete_node_first() // Delete the first node;
	{
		node *pos=start->next;
		int x=pos->key;
		delete_node(pos);
		return x;
	}

};
class LRUCache // Implementation of LRU Cache
{
	DLinkedList obj;
	unordered_map<int,node* > CacheMap; // Used to store the address of node (key,address)
	unordered_map<int,node* > :: iterator itr;

	int max_size;
	public:
    	LRUCache(int capacity)  
    	{
    		cout<<"\nNew Called\n";
        	max_size=capacity;
    	}
    	void display() // Display the HashSet 
    	{
    		for(itr=CacheMap.begin();itr!=CacheMap.end();itr++)
    			cout<<itr->first<<" ";
    	}
    	int get(int key) // return the value at given position if found 
    	{
    		node *temp;
    		if(CacheMap.find(key)==CacheMap.end())
        		return -1;
        	else
        	{
        		temp=CacheMap[key];
        		int value=obj.get(temp);

        		obj.delete_node(temp);  // delete the last accesed node 
        		temp=obj.put(key,value);	// Add the deleted value to end of the list
        		CacheMap[key]=temp; // Change address of key in HashSet

        		obj.display();
        		cout<<endl;
        		display();
        		cout<<endl;
        		return value;
        	}
        	
    	}
    
    	void put(int key, int value) 
    	{
    		if(CacheMap.find(key)!=CacheMap.end()) // if key alredy in Hashset just change its value from old to new
    		{

    			node *temp=CacheMap[key];
    			obj.change(temp,value);
    			obj.delete_node(temp);
    			temp=obj.put(key,value);
    			CacheMap[key]=temp;

    			obj.display();
        		cout<<endl;
        		display();
        		cout<<endl;
    			return;

    		}
        	if(CacheMap.size()==max_size)// If Cache is full it will just delete the first element 
        	{
        		int NewKey=obj.delete_node_first();
        		CacheMap.erase(NewKey);        	
        	}
        	node *temp=obj.put(key,value); // Add new element to end of list
        	CacheMap[key]=temp; // updating the HashSet

        	obj.display();
        	cout<<endl;
        	display();

        	cout<<endl;
    	}
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
int main()
{
	return 0;
}