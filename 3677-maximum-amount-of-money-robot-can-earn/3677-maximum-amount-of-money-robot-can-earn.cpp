class Solution {
public:
    // int f(int r,int c,int neut,vector<vector<int>>& grid,int m,int n,vector<vector<vector<int>>>& dp){
    //     if(r==m-1&&c==n-1){
    //         if(grid[r][c]>=0) return grid[r][c];
    //         else{
    //             if(neut>0) return 0;
    //             return grid[r][c];
    //         }
    //     }
    //     if(dp[r][c][neut]!=-1) return dp[r][c][neut];
    //     int ans=0;
    //     if(grid[r][c]>=0) {
    //         int right=INT_MIN,down=INT_MIN;
    //         if(c+1<n) right=f(r,c+1,neut,grid,m,n,dp);
    //         if(r+1<m) down=f(r+1,c,neut,grid,m,n,dp);
    //         ans=grid[r][c]+max(right,down);
    //     }
    //     else if(grid[r][c]<0){
    //         int right1=INT_MIN,right2=INT_MIN,down1=INT_MIN,down2=INT_MIN;
    //         if(c+1<n){
    //             right1=grid[r][c]+f(r,c+1,neut,grid,m,n,dp);
    //             if(neut>0) right2=f(r,c+1,neut-1,grid,m,n,dp);
    //         }
    //         if(r+1<m){
    //             down1=grid[r][c]+f(r+1,c,neut,grid,m,n,dp);
    //             if(neut>0) down2=f(r+1,c,neut-1,grid,m,n,dp);
    //         }
    //         ans=max(right1,max(right2,max(down1,down2)));
    //     }
    //     //cout<<ans<<endl;
    //     return dp[r][c][neut]=ans;
    // }
    int maximumAmount(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,0)));
        if(grid[m-1][n-1]>=0){
            for(int neut=0;neut<=2;neut++) dp[m-1][n-1][neut]=grid[m-1][n-1];
        }else{
            dp[m-1][n-1][0]=grid[m-1][n-1];
            dp[m-1][n-1][1]=dp[m-1][n-1][2]=0;
        }

        for(int r=m-1;r>=0;r--){
            for(int c=n-1;c>=0;c--){
                if(r==m-1&&c==n-1) continue;
                for(int neut=0;neut<=2;neut++){
                    int ans=0;
                    if(grid[r][c]>=0) {
                        int right=INT_MIN,down=INT_MIN;
                        if(c+1<n) right=dp[r][c+1][neut];
                        if(r+1<m) down=dp[r+1][c][neut];
                        ans=grid[r][c]+max(right,down);
                    }
                    else if(grid[r][c]<0){
                        int right1=INT_MIN,right2=INT_MIN,down1=INT_MIN,down2=INT_MIN;
                        if(c+1<n){
                            right1=grid[r][c]+dp[r][c+1][neut];
                            if(neut>0) right2=dp[r][c+1][neut-1];
                        }
                        if(r+1<m){
                            down1=grid[r][c]+dp[r+1][c][neut];
                            if(neut>0) down2=dp[r+1][c][neut-1];
                        }
                        ans=max(right1,max(right2,max(down1,down2)));
                    }
                    //cout<<ans<<endl;
                    dp[r][c][neut]=ans;
                }
            }
        }
        return dp[0][0][2];
    }
};