class Solution {
public:
    /**
    compute backward the minimum health needed upon entering each cell in order to survive to the princess. Let

dp[i][j] = the minimum health you must have just before stepping into cell (i,j) so that from (i,j) onward (moving only right or down) you never drop to zero.
    */
    int f(int i,int j,vector<vector<int>>& dungeon,int m,int n,vector<vector<int>>& dp){
        if(i==m-1&&j==n-1) return max(1,1-dungeon[i][j]);
        if(dp[i][j]!=-1) return dp[i][j];
        int d=INT_MAX,r=INT_MAX;
        if(i+1<m) d=f(i+1,j,dungeon,m,n,dp);
        if(j+1<n) r=f(i,j+1,dungeon,m,n,dp);
        if(d<INT_MAX) d-=dungeon[i][j];
        if(r<INT_MAX) r-=dungeon[i][j];
        return dp[i][j]=min(max(1,d),max(1,r));
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,dungeon,m,n,dp);
    }
};