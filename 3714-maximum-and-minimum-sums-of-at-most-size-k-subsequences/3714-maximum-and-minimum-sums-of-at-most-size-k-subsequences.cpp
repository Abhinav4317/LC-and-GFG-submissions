class Solution {
public:
    const int MOD=1e9+7;
    vector<vector<long long>> binomialCoeff(int n, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long> (k + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= min(i, k); j++) {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%MOD;
            }
        }
        return dp;
    }
    int minMaxSums(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<long long>> bc=binomialCoeff(n,k);
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            int el=nums[i];
            int c1=min(n-i-1,k-1);
            int c2=min(i,k-1);
            long long mini=0,maxi=0;
            for(int j=0;j<=c1;j++) mini=(mini+bc[n-i-1][j])%MOD;
            for(int j=0;j<=c2;j++) maxi=(maxi+bc[i][j])%MOD;
            long long p1=el*1LL*mini,p2=el*1LL*maxi;
            ans=(ans+p1)%MOD;
            ans=(ans+p2)%MOD;
        }
        return (int)(ans);
    }
};