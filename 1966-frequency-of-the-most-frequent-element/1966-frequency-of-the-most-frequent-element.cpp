class Solution {
public:
    bool isPos(int ws,vector<long long>& pre,vector<int>& nums,int k,int n){
        if(ws==1) return true;
        int l=0,r=ws-1;
        while(r<n){
            long long t1=nums[r]*1LL*(r-l);
            long long t2=pre[r]-pre[l];
            if(t1-t2<=k) return true;
            r++;l++;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 1;
        sort(nums.begin(),nums.end());
        vector<long long> pre(n,0);
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1]+nums[i-1];
        }
        int s=1,e=n;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPos(mid,pre,nums,k,n)) {
                ans=mid;
                s=mid+1;
            }else e=mid-1;
        }
        return ans;
    }
};