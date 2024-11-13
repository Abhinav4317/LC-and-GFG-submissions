class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int> mp;
        unordered_map<int,int> f;
        set<int> pts;
        for(int x:nums){    
            mp[x-k]++;
            mp[x+k+1]--;
            f[x]++;
            pts.emplace(x);pts.emplace(x-k);pts.emplace(x+k+1);
        }
        int cnt=0,ans=1;
        for(auto it:pts){
            cnt+=mp[it];
            ans=max(ans,f[it]+min(cnt-f[it],numOperations));
        }
        return ans;
    }
};