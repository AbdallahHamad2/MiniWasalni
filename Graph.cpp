#include "Graph.h"

bool Graph::EdgeExists(int u, int v)
{
	for (auto& [node, weight] : AdjList[u])
	{
		if (node == v)
		{
			return true;
		}
	}
	return false;
}

void Graph::DeleteGraph()
{
	numOfVertices = 0;
	AdjList.clear();
	NameToId.clear();
	idToName.clear();
}

void Graph::CreateGraph()
{
	DeleteGraph();
	cout << "Please enter number of cities: ";
	while (!(cin >> numOfVertices) || numOfVertices < 0)
	{
		cout << "Invalid input! Number of cities can't be negative.\n";
		cout << "Please enter number of cities: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore();

	for (int i = 0; i < numOfVertices; ++i)
	{
		string s;
		cout << "Please enter the name of " << i + 1 << " city: ";
		getline(cin, s);

		if (NameToId.find(s) != NameToId.end())
		{
			cout << "City already exists! Please enter a different name." << endl;
			i--;
			continue;
		}

		NameToId[s] = i;
		idToName.push_back(s);
		AdjList.push_back({});
	}

	int NumOfEdges;
	cout << "Please enter number of edges: ";
	while (!(cin >> NumOfEdges) || NumOfEdges < 0)
	{
		cout << "Invalid input! Number of edges can't be negative.\n";
		cout << "Please enter number of edges: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore();

	for (int i = 0; i < NumOfEdges; ++i)
	{
		string src, dest;
		int weight;
		cout << "Enter the source of the " << i + 1 << " edge: ";
		getline(cin, src);
		cout << "Enter the destination of the " << i + 1 << " edge: ";
		getline(cin, dest);
		cout << "Enter the weight of the " << i + 1 << " edge: ";
		while (!(cin >> weight) || weight <= 0)
		{
			cout << "Invalid input! Only positive weights allowed.\n";
			cout << "Enter weight: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin.ignore();

		if (NameToId.find(src) == NameToId.end() || NameToId.find(dest) == NameToId.end())
		{
			cout << "Invalid Source or Destination City name!" << endl;
			i--;
			continue;
		}

		if (EdgeExists(NameToId[src], NameToId[dest]))
		{
			cout << "Edge already exists! Enter a different edge.\n";
			i--;
			continue;
		}

		AddNewEdge(NameToId[src], NameToId[dest], weight);
	}
}

void Graph::AddNewNode()
{
	cin.ignore();
	string s;
	cout << "Please enter the name of the " << numOfVertices + 1 << " th city: ";
	getline(cin, s);
	if (NameToId.find(s) != NameToId.end())
	{
		cout << "City already exists!" << endl;
		return;
	}
	AdjList.push_back({});
	NameToId[s] = numOfVertices;
	idToName.push_back(s);
	numOfVertices++;
	cout << "City Added Successfully!" << endl;
}

void Graph::UpdateAddNewEdge()
{
	cin.ignore();
	string src, dest;
	int weight;
	cout << "Enter the source of the edge: ";
	getline(cin, src);
	cout << "Enter the destination of the edge: ";
	getline(cin, dest);
	cout << "Enter the weight of the edge: ";
	while (!(cin >> weight) || weight <= 0)
	{
		cout << "Invalid input! Only positive weights allowed." << endl;
		cout << "Enter weight: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore();

	if (NameToId.find(src) == NameToId.end() || NameToId.find(dest) == NameToId.end())
	{
		cout << "Invalid Source or Destination City name!" << endl;
		return;
	}

	AddNewEdge(NameToId[src], NameToId[dest], weight);
}

void Graph::UpdateEdgeWeight()
{
	string src, dest;
	int weight;

	cin.ignore();

	cout << "Enter the source of the edge: ";
	getline(cin, src);
	cout << "Enter the destination of the edge: ";
	getline(cin, dest);
	cout << "Enter the new weight: ";
	while (!(cin >> weight) || weight <= 0)
	{
		cout << "Invalid input! Weight can only be positive!\n";
		cout << "Please enter weight: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	if (NameToId.find(src) == NameToId.end() || NameToId.find(dest) == NameToId.end())
	{
		cout << "Invalid Source or Destination City name!" << endl;
		return;
	}

	int srcId = NameToId[src];
	int destId = NameToId[dest];
	bool foundEdge = false;

	for (auto& [node, oldWeight] : AdjList[srcId])
	{
		if (node == destId)
		{
			oldWeight = weight;
			foundEdge = true;
			break;
		}
	}

	for (auto& [node, oldWeight] : AdjList[destId])
	{
		if (node == srcId)
		{
			oldWeight = weight;
			break;
		}
	}

	if (foundEdge)
		cout << "Edge weight updated successfully!" << endl;
	else
		cout << "Failed to find edge!" << endl;
}

void Graph::DeleteEdge()
{
	string src, dest;
	cin.ignore();
	cout << "Enter the source of the edge: ";
	getline(cin, src);
	cout << "Enter the destination of the edge: ";
	getline(cin, dest);

	if (NameToId.find(src) == NameToId.end() || NameToId.find(dest) == NameToId.end())
	{
		cout << "Invalid Source or Destination City name!" << endl;
		return;
	}

	int srcId = NameToId[src];
	int destId = NameToId[dest];

	bool foundEdge = false;

	for (auto it = AdjList[srcId].begin(); it != AdjList[srcId].end(); it++)
	{
		if (it->first == destId)
		{
			AdjList[srcId].erase(it);
			foundEdge = true;
			break;
		}
	}

	for (auto it = AdjList[destId].begin(); it != AdjList[destId].end(); it++)
	{
		if (it->first == srcId)
		{
			AdjList[destId].erase(it);
			break;
		}
	}

	if (foundEdge)
		cout << "Edge deleted successfully!" << endl;
	else
		cout << "Failed to find edge!" << endl;
}

void Graph::DeleteNode()
{
	string name;
	cin.ignore();
	cout << "Enter the name of the node (city) you would like to delete: ";
	getline(cin, name);
	if (NameToId.find(name) == NameToId.end())
	{
		cout << "This city doesn't exist!";
		return;
	}

	int cityId = NameToId[name];

	for (int i = 0; i < numOfVertices; ++i)
	{
		for (auto it = AdjList[i].begin(); it != AdjList[i].end();)
		{
			if (it->first == cityId)
				it = AdjList[i].erase(it);
			else
				it++;
		}
	}

	AdjList.erase(AdjList.begin() + cityId);
	idToName.erase(idToName.begin() + cityId);

	NameToId.erase(name);

	for (int i = cityId; i < numOfVertices - 1; ++i)
	{
		NameToId[idToName[i]] = i;
	}

	numOfVertices--;
	cout << "City Deleted Successfully!" << endl;
}

void Graph::AddNewEdge(int u, int v, int w)
{
	if (EdgeExists(u, v))
	{
		cout << "Edge already exists!" << endl;
		return;
	}
	AdjList[u].push_back({ v, w });
	AdjList[v].push_back({ u , w });
}

void Graph::DisplayCities()
{
	if (numOfVertices == 0)
	{
		cout << "Graph is empty!\n";
		return;
	}

	cout << "\n=======================================" << endl;
	cout << "         GRAPH STRUCTURE" << endl;
	cout << "=========================================" << endl;

	for (int i = 0; i < numOfVertices; ++i)
	{
		cout << "\nCity: " << idToName[i] << endl;
		cout << "Connected to: ";

		if (AdjList[i].empty())
		{
			cout << "No connections";
		}
		else
		{
			for (int j = 0; j < (int)AdjList[i].size(); ++j)
			{
				auto [id, weight] = AdjList[i][j];
				cout << idToName[id] << " (distance: " << weight << ")";
				if (j != (int)AdjList[i].size() - 1)
					cout << ", ";
			}
		}
		cout << endl;
	}
	cout << "=======================================" << endl;
}

void Graph::FindShortestPath()
{
	string srcName, destName;
	cin.ignore();

	cout << "Enter source city: ";
	getline(cin, srcName);

	cout << "Enter destination city: ";
	getline(cin, destName);

	if (NameToId.find(srcName) == NameToId.end() || NameToId.find(destName) == NameToId.end())
	{
		cout << "Invalid Source or Destination City name!" << endl;
		return;
	}

	int srcId = NameToId[srcName];
	int destId = NameToId[destName];

	int choice;
	cout << "Enter whice algorithm to use (0: Dijkstra, 1: Bellman Ford): ";
	cin >> choice;
	if (choice == 0)
		Dijkstra(srcId, destId);
	else
		BellmanFord(srcId, destId);
}

void Graph::Dijkstra(int src, int dest)
{
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> parents(numOfVertices, -1);
	vector<int> dist(numOfVertices, INT_MAX);
	dist[src] = 0;
	pq.push({ 0, src });

	while (!pq.empty())
	{
		auto [distance, node] = pq.top();
		pq.pop();
		if (node == dest)
		{
			stack<int> path;
			while (node != -1)
			{
				path.push(node);
				node = parents[node];
			}
			cout << "Shortest path is: ";
			while (!path.empty())
			{
				int city = path.top();
				path.pop();

				cout << idToName[city];
				if (!path.empty()) cout << " -> ";
			}
			cout << " with distance: " << dist[dest] << endl;
			break;
		}

		if (distance > dist[node])
			continue;

		for (auto& [neighbor, weight] : AdjList[node])
		{
			if (dist[node] + weight < dist[neighbor])
			{
				dist[neighbor] = dist[node] + weight;
				pq.push({ dist[neighbor], neighbor });
				parents[neighbor] = node;
			}
		}
	}

	if (dist[dest] == INT_MAX)
	{
		cout << "No Path exists between " << idToName[src] << " and " << idToName[dest] << endl;
		return;
	}
}

void Graph::BellmanFord(int src, int dest)
{
	vector<int> parents(numOfVertices, -1);
	vector<int> dist(numOfVertices, INT_MAX);
	dist[src] = 0;

	for (int i = 0; i < numOfVertices - 1; ++i)
	{
		for (int u = 0; u < numOfVertices; u++)
		{
			for (auto& [neighbor, weight] : AdjList[u])
			{
				if (dist[u] != INT_MAX && dist[neighbor] > dist[u] + weight)
				{
					dist[neighbor] = dist[u] + weight;
					parents[neighbor] = u;
				}
			}
		}
	}

	if (dist[dest] == INT_MAX)
	{
		cout << "No Path exists between " << idToName[src] << " and " << idToName[dest] << endl;
		return;
	}

	stack<int> path;
	int node = dest;
	while (node != -1)
	{
		path.push(node);
		node = parents[node];
	}

	cout << "Shortest path is: ";
	while (!path.empty())
	{
		int city = path.top();
		path.pop();

		cout << idToName[city];
		if (!path.empty()) cout << " -> ";
	}
	cout << " with distance: " << dist[dest] << endl;
}
