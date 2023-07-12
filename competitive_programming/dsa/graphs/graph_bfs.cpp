/* Traverse the following graph, source_node = 0:

					  2	
					/				
	0 ---- 3---- 1
					\
					  4
*/

#include<set>
#include<queue>
#include<unordered_map>
#include<iostream>

using namespace std;

class graph
{
private:
	unordered_map<int, bool> visited;
	queue<int> q;
	vector<int> output;

	void bfs(unordered_map<int, set<int>> &adjacency_list, unordered_map<int, bool> &visited, int node)
	{
		q.push(node);
		visited[node] = 1;

		while(!q.empty())
		{
			int frontNode = q.front();
			q.pop();

			output.push_back(frontNode);

			// Traverse all neighbpurs of frontNode

			for(auto i:adjacency_list[frontNode])
			{
				if(!visited[i])
				{
					q.push(i);
					visited[i] = 1;
				}
			}
		}
	}


public:
	unordered_map<int, set<int>> adjacency_list;

	// Assuming an undirected graph
	void addEdge(int u, int v)
	{
		adjacency_list[u].insert(v);
		adjacency_list[v].insert(u);
	}

	// void printAdjacencyList()
	// {
	// 	for(auto it1: adjacency_list)
	// 	{
	// 		cout << it1.first << ": ";
	// 		for(auto it2: it1.second)
	// 			cout << it2 << ", ";
		// 		cout << "\n"; 
	// 	}
	// }

	void traverser(int nodes)
	{
		for(int i = 0; i < nodes; i++)
			if(!visited[i])
				bfs(adjacency_list, visited, i);
	}


	void displayBFS()
	{
		for(auto it:output)
			cout << it << " ";

	}
};

int main()
{
	int n, e;

	cout << "Enter number of nodes: ";
	cin >> n;

	cout << "Enter number of edges: ";
	cin >> e;

	graph g;

	cout << "Enter edges: \n";

	for(int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}

	// cout << "Adjacency List\n";
	// g.printAdjacencyList();

	g.traverser(n);
	g.displayBFS();
}

