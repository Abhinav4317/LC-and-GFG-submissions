class Solution
{
public:
    int f(int city,int day,vector<vector<int>> &ss,vector<vector<int>> &ts,int k,int n,vector<vector<int>>& dp){
        if(day==k) return 0;
        if(dp[city][day]!=-1) return dp[city][day];
        int stay=ss[day][city]+f(city,day+1,ss,ts,k,n,dp);
        int move=-1;
        for(int i=0;i<n;i++){
            if(i==city) continue;
            move=max(move,ts[city][i]+f(i,day+1,ss,ts,k,n,dp));
        }
        return dp[city][day]=max(stay,move);
    }
    int maxScore(int n, int k,vector<vector<int>> &ss,vector<vector<int>> &ts){
        int ans=-1;
        vector<vector<int>> dp(n,vector<int>(k,-1));
        for(int i=0;i<n;i++){
            ans=max(ans,f(i,0,ss,ts,k,n,dp));
        }
        return ans;
    }
};