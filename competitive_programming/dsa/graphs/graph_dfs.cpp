/*
	To print the DFS output for

	0 ----- 2 ----- 1 
			|		|
			|		|
			4 ----- 3

Love Babbar's code with extended class modularity.
*/

// It is important to pass the variables by reference!

#include<vector>
#include<set>
#include<list>
#include<unordered_map>
#include<iostream>

using namespace std;

class graph
{
private:
	unordered_map<int, set<int>> adjacencyList;
	unordered_map<int, bool> visited;
	vector<vector<int>> output;

	void dfs(int &node, unordered_map<int, bool> &visited, unordered_map<int, set<int>> &adjacencyList, vector<int> &component)
	{
		component.push_back(node);
		visited[node] = 1;

		for(auto i: adjacencyList[node])
			if(!visited[i])
				dfs(i, visited, adjacencyList, component);
	}

public:
	void addEdges(int u, int v)
	{
		adjacencyList[u].insert(v);
		adjacencyList[v].insert(u);
	}

	void traverser(int nodes)
	{
		for(int i = 0; i < nodes; i++)
		{
			if(!visited[i])
			{
				vector<int> component;
				dfs(i, visited, adjacencyList, component);
				output.push_back(component);
			}
		}
	}

	void displayDFS()
	{
		cout << "DFS Output is: \n";
		for(auto i: output)
			for(auto j: i)
				cout << j << " ";
		
	}

	// void printAdjacencyList()
	// {
	// 	for(auto i:adjacencyList)
	// 	{
	// 		cout << i.first << ": ";

	// 		for(auto j: i.second)
	// 			cout << j << ", ";
	// 		cout << endl;
	// 	}	
	// }
};


int main()
{
	int n, e;

	cout << "Enter # nodes: ";
	cin >> n;

	cout << "Enter # edges: ";
	cin >> e;

	int u, v;
	cout << "Enter the starting and ending node for the ith edge: \n";

	graph g;

	for(int i = 0; i < e; i ++)
	{
		cin >> u >> v;
		g.addEdges(u, v);
	}

	g.traverser(n);
	// g.printAdjacencyList();

	g.displayDFS();
}

