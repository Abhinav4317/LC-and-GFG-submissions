class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        /**
        This can be achieved by propagating heights across the grid in two passes, ensuring that every cell considers its neighbors both from the previous and subsequent directions.

Important Note:
The order of these passes is flexible. You could choose:

Top-to-bottom and left-to-right followed by bottom-to-top and right-to-left (used in the explanation below).
Or reverse the order: Bottom-to-top and right-to-left followed by top-to-bottom and left-to-right.
Both approaches yield the same result because we update the heights based on all neighbors in both directions.


\U0001f4da Approach
Step 1: Initialization
Create a height matrix of size R x C (same as the grid isWater).
Initialize each cell in height to a very large value, such as R + C (ensures propagation works correctly).
Set water cells (isWater[i][j] == 1) to 0, as their height is fixed.

Step 2: Propagation in Two Passes
First Pass: Top-to-Bottom and Left-to-Right
Process the grid row by row from top to bottom and column by column from left to right.
For each cell (i, j):
If the cell has a top neighbor (i > 0), update its height:
height[i][j] = min(height[i][j], height[i - 1][j] + 1)
If the cell has a left neighbor (j > 0), update its height:
height[i][j] = min(height[i][j], height[i][j - 1] + 1)

Second Pass: Bottom-to-Top and Right-to-Left
Process the grid row by row from bottom to top and column by column from right to left.
For each cell (i, j):
If the cell has a bottom neighbor (i < R - 1), update its height:
height[i][j] = min(height[i][j], height[i + 1][j] + 1)
If the cell has a right neighbor (j < C - 1), update its height:
height[i][j] = min(height[i][j], height[i][j + 1] + 1)


\U0001f4dd Why the Order of Passes Doesn’t Matter
The goal of the two passes is to ensure that all neighbors (top, bottom, left, and right) influence the height of each cell.
By updating the matrix twice, every cell eventually considers all possible directions.
Whether you start with top-to-bottom/left-to-right or bottom-to-top/right-to-left doesn’t affect the final result.

        */
        int r=isWater.size();
        int c=isWater[0].size();
        vector<vector<int>> ans(r,vector<int>(c,r+c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(isWater[i][j]==1) {ans[i][j]=0; continue;}
                if(i-1>=0) ans[i][j]=min(ans[i][j],ans[i-1][j]+1);
                if(j-1>=0) ans[i][j]=min(ans[i][j],ans[i][j-1]+1);
            }
        }
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                //if(isWater[i][j]==0) {ans[i][j]=0; continue;}
                if(i+1<r) ans[i][j]=min(ans[i][j],ans[i+1][j]+1);
                if(j+1<c) ans[i][j]=min(ans[i][j],ans[i][j+1]+1);
            }
        }
        return ans;
    }
};