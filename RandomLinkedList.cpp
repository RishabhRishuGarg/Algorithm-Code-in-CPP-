//Problem:- 
// Generate Random linked list And generate random node from list.
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
	int data;
	ListNode* next;
};
class RandomList
{
	ListNode *root;
	int size;
public:
	RandomList(int n)
	{
		root=NULL;
		size=n;
		srand(time(NULL));
	}
	void Print()
	{
		ListNode *temp=root;
		while(temp)
		{
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		cout<<endl;
	}
	void AddNode(int x)
	{
		ListNode* temp=new ListNode;
		temp->data=x;
		temp->next=NULL;
		if(root!=NULL)
			temp->next=root;
		root=temp;

	}
	void GenerateRandomList()
	{
		for (int i = 0; i < size; ++i)
			AddNode(rand()%100);
	}
	// Here we are known to size of list so we will choose any one node from whole list
	// Using Random function is very accurate in this 
	// Because to choose any element from 0 to RAND_MAX have same probability 
	int GenerateRandomNode() 
	{
		int index=rand()%size; // Contains the index of number
		ListNode *temp=root;
		for (int i = 0; i < index; ++i)
		{
			temp=temp->next;
		}
		return temp->data;
	}
	/*
		If size of list is not known then if we want random number .
		Now we dont have size so it is tough to get the random number in one call 
		so now we will traverse our list one by one and will get the random number at earch iteration 
		say 
Iteration	Element		Probability
		
1.			A1			A1=1
2.			A1,A2		A1=1/2,A2=1/2
3.			A1,A2.A3	A3=1/2, A1=(1/2)*(1/2), A2=(1/2)*(1/2) => A1=1/4, A2=1/4

		to do this we will use random function of size 2 so that it will give the value 0,1
		On 1 we will keep our random is previous generated random 
		On 0 we will change our random to new node
		So that at every iteration we a random number
		previous figure shows that at first iteration probability to get the A2 at 3rd iteration is 1/4 
	*/
	int GenerateRandomNode1()
	{
		ListNode *temp=root;
		int Rnumber=temp->data,desc;
		temp=temp->next;
		//cout<<Rnumber<<", ";
		while(temp)
		{
			desc=rand()%2;
			if(desc==0)
				Rnumber=temp->data;
			//cout<<Rnumber<<", ";
			temp=temp->next;
		}
		//cout<<endl;
		return Rnumber;
	}
	/*
		In previous logic we have a problem we are choosing a number with different probability
		we are not choosing a nunber with equal probability

		In solution of this problem we want to give every number same probability
Iteration	Element		Probability
		
1.			A1			A1=1
2.			A1,A2		A1=1/2,A2=1/2
3.			A1,A2.A3	A3=1/3, A1=(2/3)*(1/2), A2=(2/3)*(1/2) => A1=1/3, A2=1/3

Now we will choose new element if random number generator will generater 0 value from i nunbers
so that at each iteration the new number will have the probability is 1/i and previous number have 1-1/i
	*/
	int GenerateRandomNode2()
	{
		ListNode *temp=root;
		int Rnumber=temp->data,desc;
		temp=temp->next;
		//cout<<Rnumber<<", ";
		int i=1;
		while(temp)
		{
			desc=rand()%i;
			i++;
			if(desc==0)
				Rnumber=temp->data;
			//cout<<Rnumber<<", ";
			temp=temp->next;
		}
		//cout<<endl;
		return Rnumber;
	}



};
int main()
{
	int n;
	n=rand()%100;
	RandomList obj(n);
	obj.GenerateRandomList();
	obj.Print();
	cout<<"Random node is "<<obj.GenerateRandomNode()<<endl;
	cout<<"Random node is "<<obj.GenerateRandomNode1()<<endl;
	cout<<"Random node is "<<obj.GenerateRandomNode2()<<endl;
}