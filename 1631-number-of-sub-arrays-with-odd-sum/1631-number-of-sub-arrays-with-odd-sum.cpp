class Solution {
public:
    const int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(arr[i]%2) v.push_back(i);
        }
        //unordered_map<int,pair<int,int>> mp;
        long long cnt=0,ans=0;
        for(int i=v.size()-1;i>=0;i-=2){
            int ind=v[i];
            int r=(i==v.size()-1)?n:v[i+1];
            int rc=r-ind-1;
            int l=(i==0)?-1:v[i-1];
            int lc=ind-l;
            cnt=(cnt+rc)%MOD;
            long long tot=(lc+(lc*1LL*cnt)%MOD)%MOD;
            cnt=(cnt+1)%MOD;
            ans=(ans+tot)%MOD;
        }
        cnt=0;
        for(int i=v.size()-2;i>=0;i-=2){
            int ind=v[i];
            int r=(i==v.size()-1)?n:v[i+1];
            int rc=r-ind-1;
            int l=(i==0)?-1:v[i-1];
            int lc=ind-l;
            cnt=(cnt+rc)%MOD;
            long long tot=(lc+(lc*1LL*cnt)%MOD)%MOD;
            cnt=(cnt+1)%MOD;
            ans=(ans+tot)%MOD;
        }
        return ans;
    }
};