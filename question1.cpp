#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjacencyList(int V, int E, vector<vector<int>>& edges) {
    // Initialize the adjacency list with V empty lists
    vector<vector<int>> adjList(V);
    
    // Populate the adjacency list
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v); // Add v to u's list
        adjList[v].push_back(u); // Add u to v's list (undirected)
    }
    
    return adjList;
}

int main() {
    int V = 6; // Number of vertices
    int E = 8; // Number of edges
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {1, 5}, {0, 4}};
    
    vector<vector<int>> adjList = createAdjacencyList(V, E, edges);
    
    // Print the adjacency list
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    
    return 0;
}
