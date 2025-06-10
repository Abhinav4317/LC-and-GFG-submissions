class Solution {
public:
    long long inf=-1e15;
    long long f(int ind,int prev,int k,vector<int>& prices,int n,vector<vector<vector<long long>>>& dp){
        if(k==0||ind==n) return (prev==0)?0:inf;
        if(dp[ind][prev][k]!=-1) return dp[ind][prev][k];
        if(prev==0){
            long long t1=-prices[ind]+f(ind+1,1,k,prices,n,dp);
            long long t2=prices[ind]+f(ind+1,2,k,prices,n,dp);
            long long t3=f(ind+1,0,k,prices,n,dp);
            return dp[ind][prev][k]=max(t1,max(t2,t3));
        }else if(prev==1){
            long long t1=prices[ind]+f(ind+1,0,k-1,prices,n,dp);
            long long t2=f(ind+1,1,k,prices,n,dp);
            return dp[ind][prev][k]=max(t1,t2);
        }else{
            long long t1=-prices[ind]+f(ind+1,0,k-1,prices,n,dp);
            long long t2=f(ind+1,2,k,prices,n,dp);
            return dp[ind][prev][k]=max(t1,t2);
        }
        return 0;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(3,vector<long long>(k+1,-1)));

        return f(0,0,k,prices,n,dp);
    }
};