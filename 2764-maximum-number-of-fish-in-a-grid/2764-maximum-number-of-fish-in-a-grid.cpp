class Solution {
public:
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};
    int dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& vis,int m,int n){
        vis[r][c]=1;
        int ans=grid[r][c];
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]>0&&!vis[nr][nc]){
                ans+=dfs(nr,nc,grid,vis,m,n);
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0&&!vis[i][j]){
                    int sum=dfs(i,j,grid,vis,m,n);
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};