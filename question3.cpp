//Name: Sophie
//Student ID: 1123504
//Due Date: Dec 12.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Helper function to perform DFS recursively
void performDFS(int vertex, const vector<vector<int>>& adjacencyList, vector<bool>& visitedNodes, vector<int>& traversalOrder) {
    visitedNodes[vertex] = true;
    traversalOrder.push_back(vertex);

    for (int neighbor : adjacencyList[vertex]) {
        if (!visitedNodes[neighbor]) {
            performDFS(neighbor, adjacencyList, visitedNodes, traversalOrder);
        }
    }
}

// Function to initiate the DFS traversal
vector<int> depthFirstSearch(const vector<vector<int>>& adjacencyList) {
    int totalVertices = adjacencyList.size();
    vector<bool> visitedNodes(totalVertices, false);
    vector<int> traversalOrder;

    performDFS(0, adjacencyList, visitedNodes, traversalOrder);

    return traversalOrder;
}

int main() {
    vector<vector<int>> adjacencyList = {
        {1, 2},
        {0, 2},
        {0, 1, 3, 4},
        {2},
        {2}
    };

    vector<int> dfsResult = depthFirstSearch(adjacencyList);

    cout << "DFS Traversal Output: ";
    for (int vertex : dfsResult) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
