class Solution {
public:
/**
Intuition
The problem requires us to divide a graph into groups where each group contains only connected nodes, and each group's depth is maximized. The main challenges are:

Finding connected components in the graph.
Checking if the component is bipartite (ensuring no two adjacent nodes have the same depth).
Maximizing the number of groups that can be formed.
To achieve this, we:

Identify all connected components.
Try different nodes as starting points and compute the maximum possible depth.
Check if the graph contains an odd-length cycle (i.e., if it’s not bipartite).
Approach
Graph Construction

Convert the edges list into an adjacency list representation (graph).
Use a visited array to track the depth of each node.
Find Connected Components

Iterate over all nodes.
If a node is not visited, find all nodes in its connected component using DFS/BFS.
Bipartiteness Check and Max Depth Calculation

For each connected component, attempt to find the maximum group size by using BFS.
If we detect an odd-length cycle (non-bipartite component), return -1.
Summing Up Maximum Depths

Each connected component contributes the maximum depth obtained from different starting nodes.
Complexity
Time Complexity:

Constructing the graph takes O(E) where E is the number of edges.
Finding connected components takes O(N + E) since each node and edge is visited once.
Checking for bipartiteness and computing maximum depth also runs in O(N + E).
Total: O(N + E).
Space Complexity:

Adjacency list storage: O(N + E).
Visited array: O(N).
Queue storage in BFS: O(N).
Total: O(N + E).
*/
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1, -1);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int maxGroups = 0;
        unordered_set<int> componentNodes;
        
        for (int i = 1; i <= n; i++) {
            if (visited[i] != -1) continue;
            
            componentNodes.clear();
            findConnectedComponent(i, graph, componentNodes);
            
            int maxDepth = -1;
            for (int node : componentNodes) {
                maxDepth = max(maxDepth, getMaxDepth(node, componentNodes, graph, visited));
            }
            
            if (maxDepth == -1) return -1;
            maxGroups += maxDepth;
        }
        
        return maxGroups;
    }

private:
    void findConnectedComponent(int node, vector<vector<int>>& graph, unordered_set<int>& componentNodes) {
        componentNodes.insert(node);
        for (int neighbor : graph[node]) {
            if (componentNodes.count(neighbor) == 0) {
                findConnectedComponent(neighbor, graph, componentNodes);
            }
        }
    }

    int getMaxDepth(int start, unordered_set<int>& componentNodes, vector<vector<int>>& graph, vector<int>& visited) {
        for (int node : componentNodes) visited[node] = -1;
        
        queue<int> q;
        int depth = 1;
        
        q.push(start);
        visited[start] = 1;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int neighbor : graph[cur]) {
                if (visited[neighbor] == -1) {
                    visited[neighbor] = visited[cur] + 1;
                    depth = max(depth, visited[neighbor]);
                    q.push(neighbor);
                } else if (abs(visited[cur] - visited[neighbor]) != 1) {
                    return -1;
                }
            }
        }
        
        return depth;
    }
};