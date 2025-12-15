# Mini Wasalni - Town Navigation System

A C++ console application that implements a graph-based navigation system for finding shortest paths between cities. The name "Wasalni" means "get me there" in Arabic, reflecting the app's purpose of helping users navigate between towns.

## Features

- **Graph Creation**: Build a network of cities with weighted connections representing distances
- **Dynamic Graph Updates**:
  - Add new cities to the network
  - Create new connections between cities
  - Modify existing road distances
  - Remove cities or connections
- **Shortest Path Algorithms**:
  - **Dijkstra's Algorithm**: Efficient shortest path finding
  - **Bellman-Ford Algorithm**: Alternative pathfinding with negative weight detection capability
- **Interactive Console Interface**: User-friendly menu-driven system
- **Graph Display**: Display the complete network structure with all connections

## Technical Implementation

### Data Structures
- **Adjacency List**: Efficient graph representation using `vector<vector<pair<int, int>>>`
- **Hash Maps**: Fast city name-to-ID lookup using `unordered_map`
- **Priority Queue**: Used in Dijkstra's algorithm for optimal performance

### Algorithms
- **Dijkstra's Algorithm**: O((V + E) log V) time complexity
- **Bellman-Ford Algorithm**: O(V × E) time complexity, handles more general cases

## Installation & Compilation

### Prerequisites
- C++ compiler with C++17 support or higher (GCC, Clang, MSVC)
- Make utility
- Standard Template Library (STL)

### Building the Project
```bash
# Compile the project
make

# Run the program
./mini_wasalni
```

### Additional Make Commands
```bash
# Clean build files
make clean

# Rebuild from scratch
make clean && make
```

## Usage Guide

### 1. Creating a Graph
- Select option `1` from the main menu
- Enter the number of cities
- Provide names for each city
- Enter the number of road connections
- For each connection, specify:
  - Source city
  - Destination city
  - Distance (weight)

### 2. Updating the Graph
Select option `2`, then choose:
- **a**: Add a new city to the network
- **b**: Create a new road between existing cities
- **c**: Update the distance of an existing road
- **d**: Remove a road connection
- **e**: Delete a city (removes all its connections)

### 3. Finding Shortest Path
- Select option `5`
- Enter source city name
- Enter destination city name
- Choose algorithm (0 for Dijkstra, 1 for Bellman-Ford)
- View the shortest path and total distance

### 4. Display Graph
- Select option `4` to view all cities and their connections



## Limitations

- Undirected graph only (roads are bidirectional)
- Positive weights only for distances
- No support for saving/loading graph data
- Console-based interface only

---

**Note**: This is an educational project designed to demonstrate graph algorithms and data structure implementations in C++.
