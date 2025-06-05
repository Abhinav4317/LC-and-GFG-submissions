class Solution {
public:
    int f(int ind,int n,string s,vector<int>& dp){
        if(ind==n) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int w1=0;
        if(ind+1<=n) w1+=f(ind+1,n,s,dp);
        if(ind+2<=n&&((s[ind]-'0')*10+(s[ind+1]-'0'))<=26) w1+=f(ind+2,n,s,dp);
        return dp[ind]=w1;
    }
    int numDecodings(string s) {
        int i=0,j=0,ans=1,n=s.size();
        vector<int> dp(n,-1);
        while(j<n){
            if(s[j]=='0'){
                if(j-1<0) return 0;
                if(s[j-1]=='0'||(s[j-1]-'0')>=3) return 0;
                ans*=f(i,j-1,s,dp);
                //cout<<ans<<endl; 
                i=j+1;
            }
            j++;
        }
        if(i<n) ans*=f(i,n,s,dp);
        return ans;
    }
};