class Solution {
public:
    const int MOD=1e9+7;
    int f(int r,int c,int x,vector<vector<int>>& grid,int m,int n,int k,vector<vector<vector<int>>>& dp){
        if(r==m-1&&c==n-1){
            x=x^grid[m-1][n-1];
            return (x==k);
        }
        x=x^grid[r][c];
        if(dp[r][c][x]!=-1) return dp[r][c][x];
        int cnt=0;
        if(c+1<n) cnt=(cnt+f(r,c+1,x,grid,m,n,k,dp))%MOD;
        if(r+1<m) cnt=(cnt+f(r+1,c,x,grid,m,n,k,dp))%MOD;
        return dp[r][c][x]=cnt;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(17,-1)));
        return f(0,0,0,grid,m,n,k,dp);
    }
};