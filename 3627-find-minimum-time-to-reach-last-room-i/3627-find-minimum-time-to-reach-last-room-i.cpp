#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        
        // Min-heap for priority queue: (time to reach cell, (row, col))
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        
        // Distance array to store minimum time to reach each cell
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[0][0] = 0;
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            int r = pos.first, c = pos.second;
            pq.pop();
            
            // If we reached the bottom-right cell, return the time
            if (r == m - 1 && c == n - 1) return time;
            
            // Explore all four possible directions
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                
                if (isValid(nr, nc, m, n)) {
                    int waitTime = moveTime[nr][nc];
                    int newTime = (time <= waitTime) ? waitTime + 1 : time + 1;
                    
                    // If we found a shorter path to (nr, nc), update and push to queue
                    if (newTime < distance[nr][nc]) {
                        distance[nr][nc] = newTime;
                        pq.push({newTime, {nr, nc}});
                    }
                }
            }
        }
        
        return -1; // If destination is unreachable
    }
};
