#include<bits/stdc++.h>
#define threshold 2
using namespace std;
/*Below Code is implementation of HashSet With 4 Function
1. Insert an element
2. Delete an element 
3. Search an element
4. Get the size of HashSet

All 4 operation have constant runtime  
*/
class HashSet
{
	int size,buckets;
	list<int> *graph;
	list<int> *graph1;
	list<int>:: iterator itr;
public:
		HashSet(int n) // Constructor initialize the buckets size and create buckets
		{
			buckets=n;
			size=0;
			graph=new list<int>[n];
		}
		void add_edge(int u,int v) // Add an edge to a bucket TC:-  O(1)
		{
			graph[u].push_back(v);
			size++;
		}
		int HashFunction(int n) // return the key derived from hash function TC:- O(1)
		{
			return n%buckets;
		}
		bool search(int x) // search for the element in the Hash Table TC:- O(1)
		{
			int index=HashFunction(x);
			for(itr=graph[index].begin();itr!=graph[index].end();itr++)
			{
				if(x==(*itr)) return true;
			}
			return false;
		}
		void print_graph()
		{
			for(int i=0;i<buckets;i++)
			{
				cout<<i<<"-> ";
				for(itr=graph[i].begin();itr!=graph[i].end();itr++)
				{
					cout<<*itr<<" ";
				}
				cout<<endl;
			}	
		}
		void reallocate() // This function reallocates the memory of big size when size of Hashset crosses the threshold
		{
			int temp=buckets;
			buckets=buckets*2;
			graph1=new list<int>[buckets];
			for(int i=0;i<temp;i++)
			{
				for(itr=graph[i].begin();itr!=graph[i].end();itr++)
				{
					int index=HashFunction(*itr);
					graph1[index].push_back(*itr);
				}
			}
			for(int i=0;i<temp;i++)
			{
				while(!graph[i].empty())
					graph[i].pop_front();
			}	
			delete[] graph;
			graph=graph1;

		}
		bool put(int n) // Add new element to the hash table 
		{
			int index=HashFunction(n);
			if(!search(n))
			{
				
				if(threshold<=(size/buckets))
					reallocate();
				add_edge(index,n);
			}
			else
				return false;
			return true;
		}
		int Size()
		{
			return size;
		}
		bool remove(int n) // remove an element from Hash Table
		{
			if(search(n))
			{
				int index=HashFunction(n);
				graph[index].remove(n);
				size--;
			}
			else
				return false;
			return true;
		}
};
int main()
{
	HashSet h(5);
	int n,x;
	while(true)
	{
		cout<<"1. Add an element \n";
		cout<<"2. Remove an element \n";
		cout<<"3. Search an element \n";
		cout<<"4. Size \n";
		cout<<"5. Display the elements \n";
		cout<<"6. Exit \n";
		cout<<"Enter any choice:- ";
		cin>>n;
		switch(n)
		{
			case 1 :
					cout<<"Enter the element :- ";
					cin>>x;
					if(h.put(x))
						cout<<"Element Entered"<<endl;
					else
						cout<<"Error occured Check input"<<endl;
					break;
			case 2 :
					cout<<"Enter the element :- ";
					cin>>x;
					if(h.remove(x))
						cout<<"Element Deleted"<<endl;
					else
						cout<<"Not Deleted"<<endl;
					break;
			case 3 :
					cout<<"Enter the element :- ";
					cin>>x;
					if(h.search(x))
						cout<<"Element Found"<<endl;
					else
						cout<<"Not Found"<<endl;
					break;
			case 4 :
					cout<<h.Size();
					break;
			case 5 :
					h.print_graph();
					break;
			case 6 :
					return 0;
		}
	}

}