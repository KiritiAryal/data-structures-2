#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct Graph {
	int numVertices;
	list<int>* adjLists;

	Graph(int numVertices) {
		this->numVertices = numVertices;
		adjLists = new list<int>[numVertices];
	}
	void addEdge(int src, int dest)
	{
		adjLists[src].push_back(dest);
	}
	void BFS(int startVertex)
	{
		bool* visited = new bool[numVertices];
		for (int i = 0; i < numVertices; i++)
			visited[i] = false;
		list<int> q;
		visited[startVertex] = true;
		q.push_back(startVertex);
		list<int>::iterator i;
		while (!q.empty())
		{
			startVertex = q.front();
			cout << "Visited " << startVertex << endl;
			q.pop_front();
			for (i = adjLists[startVertex].begin(); i != adjLists[startVertex].end(); ++i)
			{
				if (!visited[*i])
				{
					visited[*i] = true;
					q.push_back(*i);
				}
			}

		}
	}
};


int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.BFS(1);
	return 0;
}