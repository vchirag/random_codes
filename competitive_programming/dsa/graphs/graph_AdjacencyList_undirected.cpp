/*

	0 -----	1  
	|		|  \
	|		|	2
	|		|  /
	4 ----- 3
*/
// CodeHelp- by Babbar

#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
template <typename type>

class graph
{
	public:
		unordered_map<type, list<type>> adj;

		void addEdge(type u, type v, bool direction)
		{
			// direction 1 = directed graph
			// direction 0 = undirected graph
			// u = first node
			// v = second node

			// create an edge from u to v
			adj[u].push_back(v);

			if(direction == 0)
			{
				adj[v].push_back(u);
			}
		}

		void printAdjList()
		{
			for(auto i:adj)
			{
				cout << i.first << "-> ";
				
				for(auto j:i.second)
					cout << j << ", ";

				cout <<"\n";
			}
		}
};


int main()
{
	int n, m;

	cout << "# Nodes: ";
	cin >> n;

	cout << "# Edges: ";
	cin >> m;

	graph<int> g;

	for(int i = 0; i < m; i++)
	{
		int u,v;
		cin >> u >> v;
		g.addEdge(u, v, 0);
	}

	g.printAdjList();
}
