// using adjacency list
//Link to problem https://www.hackerrank.com/challenges/journey-to-the-moon
#include<bits/stdc++.h>
using namespace std;
struct element // defining the structure of node
{
	int number;
	struct element *next;
};
struct element *createNew(int data) // createing new node
{
	struct element *new_node=new element;
	new_node->number=data;
	new_node->next=NULL;
	return new_node;
}
void insert(int data, element **list,int i) //inserting new node to given i and
											// stores the data in into list new node
{
	element *new_node=createNew(data);
	element *ptr=list[i];
	if(list[i]==NULL)
	{
		list[i]=new_node;
	}
	else
	{
		while(ptr->next!=NULL) ptr=ptr->next;
		ptr->next=new_node;
	}
}
unsigned long long int calculate_pair(int *groups,int n)
{
	int *sumupto=new int[n];
    unsigned long long int total=0;
	sumupto[n-1]=groups[n-1];
	/*
		This function calulate the total permutations of pair of two from diffrent groups(Region) members 
		first loop is used to calculate the sum of group members from last to first
		(A1,A2,A3,A4,.......,An ) ai is numbers of members in diffrent regions
		total permutations = A1*(A2+A3+A4+......+An)+A2*(A3+A4+A5+.......An)+..........+An-1*An
		so first loop calculates the sum from last because the sum is repeating in further products
	*/
	for (int i=n-2;i>=0;i--)
	{
		sumupto[i]=sumupto[i+1]+groups[i];
	}
	/*
		This loop calculates the total permutations by producting the group array to sumupto array
		
	*/
	for (int i=0;i<n-1;i++)
	{
		total=total+(groups[i]*sumupto[i+1]);
	}
	
	return total;	
}
void print_graph(element **list,int vertex)
{
	for(int i=0;i<vertex;i++)
	{
		element *ptr=list[i];
		printf("for %d :- ",i );
		if(ptr!=NULL)
		{
			while(ptr!=NULL)
			{
				printf("%d\t",ptr->number);
				ptr=ptr->next;
			}
		}
		printf("\n");
	}
}
unsigned long long int create_groups(element **data,int n)
{
	int *groups=new int[n];
	int *visited=new int[n];
    int *p_visit=new int[n];
	int group_i=0;
	stack <int> s;
	/*
		this process is the same solution as to find the diffrent disconnected graphs 
		and saving the numbers of nodes in all graphs
	*/
	for(int i=0;i<n;i++)// initializing the array 
	{
		groups[i]=0; // it is used to store the diffrent node in particular graph
		visited[i]=0; // it will track on node wheather the node is visited or not
        p_visit[i]=0; // it will track on node wheather the node is pushed in stack or not
	}
	/*
		group creation is done using DFS 
		the process start from first node and checking the graph connectivity by traversing it using 
		DFS algorithm 
		at every push in stack is increasing the node in graph.
	*/
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			int x;
			visited[i]=1;
			
			s.push(i);
            p_visit[i]=1;
            groups[group_i]++;
			while(!s.empty())
			{
				//groups[group_i]++;
				x=s.top();
				s.pop();
				visited[x]=1;
				element *ptr=data[x];
				int j;
				while(ptr!=NULL)
				{
					j=ptr->number;
					if(visited[j]==0)
                    {
                        if(p_visit[j]==0)
                        {	
                           groups[group_i]++;
                           s.push(j);
                           p_visit[j]=1;
                         
                        }
                    }
                    ptr=ptr->next;
				}
			}
			group_i++;
		}
	}
	return(calculate_pair(groups,group_i));
	for(int i=0;i<n;i++)
	{
		printf("%d     \n",groups[i]);
	}
    //return(calculate_pair(groups,group_i));
}
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	//int **data=new int*[n];
	element **data=new element*[n];
	int a,b;
	for(int i=0;i<n;i++)
		data[i]=NULL;
	for(int i=0;i<p;i++)
	{
		scanf("%d%d",&a,&b);
		insert(a,data,b);
		insert(b,data,a);
		
	}
	//print_graph(data,n);
	cout<<create_groups(data,n);

}