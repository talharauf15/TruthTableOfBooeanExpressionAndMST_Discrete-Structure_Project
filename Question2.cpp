#include<iostream>
#include<iomanip>
using namespace std;
//ADT of node
struct node
{
	int data;
	node* next;
};
//ADT of Linked List
class LL
{
public:
	node* head = nullptr;
	node* curr = nullptr;
	//Member functions
	LL();
	bool isempty();
	void insert_end(int);
};
//Constructor
LL::LL()
{
	head = nullptr;
	curr = nullptr;
}
//CHeck if list is empty or not
bool LL::isempty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Inserting new node at end
void LL::insert_end(int value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;
	if (isempty() == true)
	{
		head = curr = temp;
	}
	else
	{
		curr->next = temp;
		curr = curr->next;
	}
}
//Graph ADT
class GraphADT
{
private:
	int** adjMatrix;
	int** PrimsMSTMatrix;
	LL* adjList;
	LL* PrimsList;
public:
	int v;
	char lastchar;
	GraphADT(int);
	void AddEdge(int src, int dest, int weight);
	void CreateMST_Prims();
	void PrintMST_Prims();
	//int getmin(int**, int&, int&);
	void DisplayMatrix();
	void DisplayList();
};
//Constructor to initialize matrix and list
GraphADT::GraphADT(int x)
{
	v = x;
	cout << "Number of vertexes : " << v << endl;
	adjList = new LL[v];
	PrimsList = new LL[v];
	for (int i = 0; i < v; ++i)
	{
		adjList[i].head = NULL;
		adjList[i].curr = adjList[i].head;
		PrimsList[i].head = NULL;
		PrimsList[i].curr = PrimsList[i].head;
	}
	adjMatrix = new int* [v];
	PrimsMSTMatrix = new int* [v];
	for (int i = 0; i < v; ++i)
	{
		adjMatrix[i] = new int[v];
		PrimsMSTMatrix[i] = new int[v];
	}
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			adjMatrix[i][j] = 0;
			PrimsMSTMatrix[i][j] = 0;
		}
	}
	lastchar = char(v + 64);
	cout << "Available vertices : ";
	for (int i = 0; i < v; ++i)
	{
		cout << " " << char(i + 65);
	}
	cout << endl;
}
void GraphADT::AddEdge(int src, int dest, int weight)
{
	if (!(src >= 'A' && src <= lastchar))
	{
		cout << "Entered source vertex is invalid!\nDosent exist\n";
	}
	else if (!(dest >= 'A' && dest <= lastchar))
	{
		cout << "Entered Destination vertex is invalid!\nDosent exist\n";
	}
	src -= 65;
	dest -= 65;
	if (adjMatrix[src][dest] != 0)
	{
		cout << "Edge already exist!\n";
	}
	else
	{
		adjList[src].insert_end(dest);
		adjList[dest].insert_end(src);
		adjMatrix[src][dest] = weight;
		adjMatrix[dest][src] = weight;
	}
}
//Function to display Adjacency matrix
void GraphADT::DisplayMatrix()
{
	cout << "\n";
	cout << setfill('-');
	cout << setw(44) << "Adjacency matrix" << setw(32);
	cout << "\nV";
	for (int i = 0; i < v; ++i)
	{
		cout << '\t' << char(i + 65);
	}
	cout << "\n |";
	cout << "--------------------------------------------------------------------- "; 
		cout << endl;
	for (int i = 0; i < v; ++i)
	{
		cout << char(i + 65) << " |";
		for (int j = 0; j < v; ++j)
		{
			cout << "\t" << adjMatrix[i][j];
		}
		if (i != v - 1)
		{
			cout << "\n | \n";
		}
	}
	cout << endl;
	cout << setfill('-');
	cout << setw(106);
}
//function to display the Adjacency list
void GraphADT::DisplayList()
{
	cout << "\n\nDisplaying Adjacency List : \n\n";
	for (int i = 0; i < v; ++i)
	{
		cout << "Vertex " << char(i + 65) << " :";
		node* curr = adjList[i].head;
		while (curr != NULL)
		{
			cout << " -> " << char(curr->data + 65);
			curr = curr->next;
		}
		cout << endl;
	}
}
//Function to make MST by Prims Algorithm
void GraphADT::CreateMST_Prims()
{
	int** temp;
	temp = new int* [v];
	for (int i = 0; i < v; ++i)
	{
		temp[i] = new int[v];
	}
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			temp[i][j] = adjMatrix[i][j];
		}
	}
	int* Vertex = new int[v];
	for (int i = 0; i < v; ++i)
	{
		Vertex[i] = 0;
	}
	int edge_count = 0;
	Vertex[0] = 1;
	cout << endl;
	while (edge_count < (v - 1))
	{
		int min = 20000;
		int x = 0;
		int y = 0;
		for (int i = 0; i < v; i++)
		{
			if (Vertex[i] == 1)
			{
				for (int j = 0; j < v; j++)
				{
					if (!(Vertex[j] == 1) && temp[i][j])
					{
						if (min > temp[i][j])
						{
							min = temp[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		PrimsMSTMatrix[x][y] = temp[x][y];
		PrimsMSTMatrix[y][x] = temp[y][x];
		PrimsList[x].insert_end(y);
		PrimsList[y].insert_end(x);
		edge_count++;
		temp[x][y] = 0;
		Vertex[y] = 1;
	}
}
//Function to display list and adj matrix of MST created by Prims Algorithm
void GraphADT::PrintMST_Prims()
{
	cout << "\n";
	cout << "\n\nDisplaying Adjacency List : \n\n";
	for (int i = 0; i < v; ++i)
	{
		cout << "Vertex " << char(i + 65) << " :";
		node* curr = PrimsList[i].head;
		while (curr != NULL)
		{
			cout << " -> " << char(curr->data + 65);
			curr = curr->next;
		}
		cout << endl;
	}
	cout << "\n";
	cout << setfill('-');
	cout << setw(44) << "Adjacency matrix" << setw(32);
	cout << "\nV";
	for (int i = 0; i < v; ++i)
	{
		cout << '\t' << char(i + 65);
	}
	cout << "\n |";
	cout << "--------------------------------------------------------------------- "; 
		cout << endl;
	for (int i = 0; i < v; ++i)
	{
		cout << char(i + 65) << " |";
		for (int j = 0; j < v; ++j)
		{
			cout << "\t" << PrimsMSTMatrix[i][j];
		}
		if (i != v - 1)
		{
			cout << "\n | \n";
		}
	}
	cout << endl;
	cout << setfill('-');
	cout << setw(106);
}
//Main program
int main()
{
	GraphADT obj(9);
	cout << "The graph is : \n";
	obj.AddEdge('A', 'B', 9);
	obj.AddEdge('A', 'C', 4);
	obj.AddEdge('B', 'E', 7);
	obj.AddEdge('B', 'D', 1);
	obj.AddEdge('B', 'C', 2);
	obj.AddEdge('C', 'D', 4);
	obj.AddEdge('C', 'F', 3);
	obj.AddEdge('D', 'E', 2);
	obj.AddEdge('D', 'F', 5);
	obj.AddEdge('E', 'F', 6);
	obj.AddEdge('E', 'G', 3);
	obj.AddEdge('F', 'G', 8);
	obj.AddEdge('F', 'H', 5);
	obj.AddEdge('G', 'H', 1);
	obj.AddEdge('G', 'I', 3);
	obj.AddEdge('H', 'I', 2);
	obj.DisplayMatrix();
	obj.DisplayList();
	cout << "Now applying prims algorithm : \n";
	obj.CreateMST_Prims();
	cout << "Displaying the minimum spanning tree : \n";
	obj.PrintMST_Prims();
	system("pause");
}
