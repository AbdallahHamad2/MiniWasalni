#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits>
#include <climits>
#include <utility> // for pair
#include <functional> // for greater
using namespace std;

class Graph
{
private:
	int numOfVertices;
	vector<vector<pair<int, int>>> AdjList;
	unordered_map<string, int> NameToId;
	vector<string> idToName;
public:
	Graph() : numOfVertices{ 0 }
	{
	}

	bool EdgeExists(int u, int v);
	void DeleteGraph();
	void CreateGraph();
	void AddNewNode();
	void UpdateAddNewEdge();
	void UpdateEdgeWeight();
	void DeleteEdge();
	void DeleteNode();
	void AddNewEdge(int u, int v, int w);
	void DisplayCities();
	void FindShortestPath();
	void Dijkstra(int src, int dest);
	void BellmanFord(int src, int dest);
};

#endif
