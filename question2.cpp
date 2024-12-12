// Name: Sophie
// Student ID: 1123504
// Date of Submission: Dec 12

#include <iostream>
#include <vector>
#include <queue>
#include <sstream> // 用來處理輸入中的空格

using namespace std;

// Function to perform BFS traversal and return the traversal order
vector<int> bfsTraversal(const vector<vector<int>>& adj)
{
    int V = adj.size();  // Number of vertices in the graph
    vector<bool> visited(V, false);  // Visited array to keep track of visited nodes
    vector<int> result;  // Vector to store the BFS traversal result

    // Create a queue for BFS
    queue<int> q;

    // Start BFS from vertex 0
    visited[0] = true;  // Mark the starting node as visited
    q.push(0);  // Push the starting node into the queue

    while (!q.empty())
    {
        // Dequeue the front node
        int node = q.front();
        q.pop();

        // Add this node to the result
        result.push_back(node);

        // Visit all unvisited neighbors of the current node
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;  // Mark neighbor as visited
                q.push(neighbor);  // Enqueue the neighbor for future processing
            }
        }
    }

    return result;  // Return the BFS traversal result
}

int main()
{
    vector<vector<int>> adj;  // Adjacency list for the graph
    string line;

    // Read input until an empty line is provided
    while (getline(cin, line))
    {
        // Check if the input line is empty to stop the loop
        if (line.empty()) break;

        // Create a vector for storing the neighbors of the current vertex
        stringstream ss(line);
        vector<int> neighbors;
        int neighbor;

        // Read all neighbors for the current vertex
        while (ss >> neighbor)
        {
            neighbors.push_back(neighbor);
        }

        // Add the neighbors to the adjacency list
        adj.push_back(neighbors);
    }

    // Perform BFS and get the result
    vector<int> result = bfsTraversal(adj);

    // Output the BFS traversal result, separated by spaces
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";  // Add a space between numbers, but not after the last one
    }
    cout << endl;

    return 0;
}
