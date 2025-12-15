#include "Graph.h"

void DisplayMenu()
{
	cout << "\n========================================\n";
	cout << "    TOWN NAVIGATION SYSTEM\n";
	cout << "========================================\n";
	cout << "1. Create Graph (Add towns and distances)\n";
	cout << "2. Update Graph:\n";
	cout << "   a. Add new city\n";
	cout << "   b. Add new edge\n";
	cout << "   c. Update edge weight\n";
	cout << "   d. Delete edge\n";
	cout << "   e. Delete city\n";
	cout << "3. Delete entire graph\n";
	cout << "4. Display graph data\n";
	cout << "5. Find shortest path\n";
	cout << "6. Exit\n";
	cout << "========================================\n";
	cout << "Enter your choice: ";
}

int main()
{
	Graph g;
	int choice;
	char subChoice;

	cout << "==================================\n";
	cout << "   Welcome to Mini Wasalni!\n";
	cout << "==================================\n";

	while (true)
	{
		DisplayMenu();
		while (!(cin >> choice))
		{
			cout << "Invalid input! Please enter a number." << endl;;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			DisplayMenu();
		}

		switch (choice)
		{
		case 1:
			g.CreateGraph();
			break;

		case 2:
			cout << "\nUpdate Options:\n";
			cout << "a. Add new city\n";
			cout << "b. Add new edge\n";
			cout << "c. Update edge weight\n";
			cout << "d. Delete edge\n";
			cout << "e. Delete city\n";
			cout << "Enter your choice: ";
			cin >> subChoice;

			switch (subChoice)
			{
			case 'a':
			case 'A':
				g.AddNewNode();
				break;
			case 'b':
			case 'B':
				g.UpdateAddNewEdge();
				break;
			case 'c':
			case 'C':
				g.UpdateEdgeWeight();
				break;
			case 'd':
			case 'D':
				g.DeleteEdge();
				break;
			case 'e':
			case 'E':
				g.DeleteNode();
				break;
			default:
				cout << "Invalid choice!\n";
			}
			break;

		case 3:
			g.DeleteGraph();
			break;

		case 4:
			g.DisplayCities();
			break;

		case 5:
			g.FindShortestPath();
			break;

		case 6:
			cout << "\nThank you for using Mini Wasalni!!\n";
			return 0;

		default:
			cout << "Invalid choice! Please try again.\n";
		}
	}

	return 0;
}
