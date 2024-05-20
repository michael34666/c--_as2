# 206917908
# michaeldadush12@gmail.com
# Michael dadush


# System Programming 2 - Assignment 2
Overview
The Graph class within the ariel namespace is designed to represent and manipulate graphs. This class offers various functionalities to load, print, and perform arithmetic operations on graphs, supporting both weighted and unweighted graphs.

Features
Load and Print Graphs: Easily load graphs from adjacency matrices and print them.
Graph Properties: Query properties like whether the graph is symmetric or weighted.
Arithmetic Operations: Perform arithmetic operations like addition, subtraction, and scaling on graphs.
Comparison Operators: Compare graphs using relational operators.
Edge Counting: Count the number of edges in the graph.
Submatrix Check: Verify if a graph is a submatrix of another.
Class Definition
Private Members
vector<vector<int>> g: Adjacency matrix representing the graph.
int size: Size of the graph.
bool graph_weighted: Indicates if the graph is weighted.
bool graph_symmetric: Indicates if the graph is  undirected.
Public Methods
Load and Print

void loadGraph(const vector<vector<int>> g): Loads the graph using the provided adjacency matrix.
void const printGraph(): Prints the graph's adjacency matrix.
Accessors

vector<vector<int>> getGraph() const: Returns the adjacency matrix of the graph.
bool getSymmetricAdjMat() const: Returns if the graph is symmetric.
bool getWeight() const: Returns if the graph is weighted.
size_t countEdges() const: Counts the number of edges in the graph.
Arithmetic Operations

Graph& operator*=(const double scalar): Scales the graph by a scalar.
Graph& operator*=(const Graph& other): Multiplies two graphs element-wise.
Graph& operator+=(const Graph& other): Adds another graph to this graph.
Graph operator+(const Graph& other): Returns the result of graph addition.
Graph& operator+(): Unary plus operator.
Graph operator*(const Graph& other): Returns the result of graph multiplication.
Graph& operator/=(const double scalar): Scales the graph by dividing by a scalar.
Graph operator-(const Graph& other): Returns the result of graph subtraction.
Graph& operator-(): Unary minus operator.
Graph& operator-=(const Graph& other): Subtracts another graph from this graph.
Graph& operator++(): Pre-increment operator.
Graph& operator--(): Pre-decrement operator.
  Graph Graph::operator++(int) after-increment operator.
  Graph Graph::operator--(int) after-decrement operator.
Comparison and Utility

bool isSubmatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) const: Checks if A is a submatrix of B.
bool operator==(const Graph& other) const: Checks equality of two graphs.
bool operator!=(const Graph& other) const: Checks inequality of two graphs.
bool operator<(const Graph& other) const: Compares if this graph is less than another graph.
bool operator<=(const Graph& other) const: Compares if this graph is less than or equal to another graph.
bool operator>(const Graph& other) const: Compares if this graph is greater than another graph.
bool operator>=(const Graph& other) const: Compares if this graph is greater than or equal to another graph.
Friend Functions
std::ostream& operator<<(std::ostream& os, const Graph& g1): Overloads the << operator to print the graph.

## Algorithms

The `Algorithms` class contains static functions that implement various graph algorithms.

### isConnected

This function checks if the graph is connected:

- Perform DFS on the entire graph.
- If all vertices are discovered, the graph is connected.

### shortestPath

This function finds the shortest path between two vertices in the graph. It uses one of three algorithms based on the type of graph and weights:

- If the graph is unweighted, it uses Breadth-First Search (BFS).
- If the graph has negative weights, it uses the Bellman-Ford algorithm.

If there is no path between the two vertices, the function returns "-1".

### isContainsCycle

This function checks if the graph contains a cycle. If a cycle exists, the function returns one of the cycles in the format. If no cycle exists, it returns "-1".

#### Helper Function

- `isContainsCycleUtil`: This is a modified version of DFS that runs until it finds a back edge in the graph. When it finds a back edge, it constructs the cycle path.

### isBipartite

This function checks if the graph is bipartite. If the graph is bipartite, it returns two sets of vertices. O therwise, it returns "The graph is not bipartite".

### negativeCycle

This function checks if the graph contains a negative cycle using the Bellman-Ford algorithm. If a negative cycle exists return true Otherwise, return false.

