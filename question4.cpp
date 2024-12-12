//Name: Sophie
//Student ID: 1123504
//Due Date: Dec 12.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the sum of the MST weights using Prim's Algorithm
int primMST(int V, const vector<vector<pair<int, int>>>& adj)
{
    // Create a priority queue to store (weight, vertex) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> minWeight(V, INT_MAX);  // Array to store the minimum weight to connect each vertex
    vector<bool> inMST(V, false);  // Array to check if the vertex is included in the MST

    int totalWeight = 0;  // Variable to store the total weight of the MST

    // Start from vertex 0
    minWeight[0] = 0;
    pq.push({0, 0});  // Push the start vertex (weight 0, vertex 0)

    while (!pq.empty())
    {
        // Get the vertex with the minimum weight from the priority queue
        int u = pq.top().second;
        pq.pop();

        // If the vertex is already in MST, skip it
        if (inMST[u]) continue;

        // Add this vertex to MST and add its weight to the totalWeight
        inMST[u] = true;
        totalWeight += minWeight[u];

        // Update the weights for all adjacent vertices
        for (const auto& edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            // If the adjacent vertex is not in MST and the weight is smaller, update it
            if (!inMST[v] && weight < minWeight[v])
            {
                minWeight[v] = weight;
                pq.push({minWeight[v], v});
            }
        }
    }

    return totalWeight;  // Return the total weight of the MST
}

int main()
{
    int V, E;

    // Read the number of vertices (V) and edges (E)
    cout << "V and E: ";
    cin >> V >> E;

    // Adjacency list to store the graph
    vector<vector<pair<int, int>>> adj(V);

    // Read the edges and their weights
    for (int i = 0; i < E; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        // Since the graph is undirected, add both directions
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Calculate and output the total weight of the MST
    int mstWeight = primMST(V, adj);
    cout << "Sum of the weights: " << mstWeight << endl;

    return 0;
}
