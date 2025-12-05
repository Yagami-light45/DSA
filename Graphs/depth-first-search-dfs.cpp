//TC : O(V+2E)   
//SC : O(3V)  for stackspace , visited vector , result vector

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to perform DFS traversal
    void dfs(int v, vector<int> adj[], vector<int>& visited, vector<int>& result) {
        visited[v] = 1;         // Mark current node as visited
        result.push_back(v);        // Store node in result

        // Traverse all neighbours
        for (int u : adj[v]) {
            if (!visited[u]) {              // if neighbor not visited
                dfs(u, adj, visited, result);
            }
        }
    }
};

int main() {
    // Number of vertices
    int V = 5;

    // Adjacency list
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // Visited array
    vector<int> visited(V, 0);

    // Result vector
    vector<int> result;

    // Create object
    Solution sol;

    // Run DFS from node 0
    sol.dfs(0, adj, visited, result);

    // Print traversal
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}