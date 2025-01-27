class Solution {
public:
/**
Intuition
The problem essentially asks us to find the maximum number of employees who can be invited to a meeting, where each employee only attends if they can sit next to their favorite employee. This forms a directed graph, where each employee points to exactly one other employee (their favorite).

The challenge is to identify the largest connected group (chain) of employees and cycles within this directed graph. The main idea is that we need to:

Identify chains of employees, where each employee is connected by their favorite.
Detect cycles within the graph, where employees form loops of favorite relationships.
Maximize the number of employees that can be invited by combining the largest chain(s) with the largest cycle(s).
Approach
The solution can be broken down into several steps:

1. In-degree Calculation
Each employee has a favorite person, forming a directed edge in the graph. We first calculate the in-degree for each employee, which tells us how many employees point to them. This is helpful to find chains.

2. Topological Sorting (for Chains)
To identify the chains, we need to process the employees who are not pointed to by anyone (i.e., those with an in-degree of 0). These employees are the "starting points" of chains, and we can process them iteratively to propagate chain lengths.

3. Cycle Detection
Once we process the employees with in-degree 0, the remaining unprocessed employees form cycles. These cycles must be detected and their lengths calculated.

4. Handling Cycles of Length 2
Special handling is needed for cycles of length 2 (where two employees point to each other). These cycles are treated in a way that accounts for additional employees that can be connected to them through chains.

5. Combining Chains and Cycles
The goal is to return the maximum number of employees that can be invited. This would either be the size of the largest cycle or the size of the largest chain (or a combination of both, if there are connections between chains and cycles).

Complexity
Time complexity: O(n)
This is because we are visiting each employee once and processing each connection (each favorite relationship) a constant number of times.

Space complexity: O(n)
We store arrays for in-degrees, chain lengths, and visited status, all of which require space proportional to the number of employees.
*/
    int maximumInvitations(vector<int>& favorites) {
        int n = favorites.size();
        vector<int> inDegree(n, 0), chainLengths(n, 0);
        vector<bool> visited(n, false);

        for (int fav : favorites) {
            inDegree[fav]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;

            int next = favorites[node];
            chainLengths[next] = chainLengths[node] + 1;
            if (--inDegree[next] == 0) {
                q.push(next);
            }
        }

        int maxCycle = 0, totalChains = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int current = i, cycleLength = 0;
                while (!visited[current]) {
                    visited[current] = true;
                    current = favorites[current];
                    cycleLength++;
                }

                if (cycleLength == 2) {
                    totalChains += 2 + chainLengths[i] + chainLengths[favorites[i]];
                } else {
                    maxCycle = max(maxCycle, cycleLength);
                }
            }
        }

        return max(maxCycle, totalChains);
    }
};