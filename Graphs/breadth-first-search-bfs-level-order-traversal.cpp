    // BFS  is a graph traversal algorithm that explores all nodes level by level (or breadth-wise)   
    // Idea:
    // Use a queue (FIFO order).
    // Start from the source node and mark it visited.
    // Pop a node from the queue → visit all unvisited neighbors, and add them to the queue.
    // Repeat until the queue is empty.

    // TC  O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
    //SC O(3N)      queue data structure visited array and an adjacency list

    #include <bits/stdc++.h>
using namespace std;

// BFS function to traverse the graph
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);                  // visited array
    vis[0] = 1; 
    queue<int> q;
    q.push(0);                              // push the initial starting node 

    vector<int> bfs;                        //answer

    while (!q.empty()) {
        int node = q.front();                // get the topmost element in the queue
        q.pop(); 
        bfs.push_back(node); 

        
        for (auto it : adj[node]) {             // visit all unvisited neighbors
            if (!vis[it]) {
                vis[it] = 1;                     // store in Q and mark as visited 
                q.push(it); 
            }
        }
    }
    return bfs;     
}

// function to add an undirected edge
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}   

// print the BFS traversal
void printAns(vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int V = 5;
    vector<int> adj[V];

    // Building graph
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    // Perform BFS
    vector<int> ans = bfsOfGraph(V, adj);

    // Print result
    printAns(ans);

    return 0;
}
