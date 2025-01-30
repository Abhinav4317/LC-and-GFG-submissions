class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        /**
        The solution relies on the observation that we must cross each row and each column between given positions to get from the startPos to the homePos. So, we will always incur cost of each row and column between home and start positions atleast once.

It must also be observed that it's always best to travel through rows and column in the direction of start to end position and never beneficial to go in the opposite direction since we would then incur costs twice with no benefits. That is, we must traverse the shortest path from start to end.

In the below solution, we are travelling from end to start just to avoid extra condition (as we incur cost of rows & columns of ending cell but not of the start cell).
         */
        int ans = 0;
        for(int i = homePos[0]; i != startPos[0]; i += i > startPos[0] ? -1 : 1)  // move row-wise from end to start
            ans += rowCosts[i];
        for(int i = homePos[1]; i != startPos[1]; i += i > startPos[1] ? -1 : 1)  // move col-wise from end to start
            ans += colCosts[i];
        return ans;
    }
};