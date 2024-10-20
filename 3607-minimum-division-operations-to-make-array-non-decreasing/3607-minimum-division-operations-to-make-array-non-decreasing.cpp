class Solution {
public:
    int fn(int x){
        int ans=-1;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                ans=max(ans,max(i,x/i));
            } 
        }
        if(ans==-1) ans=1;
        return ans;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> minr(n,-1);
        int mini=nums[n-1];
        int ans=0;
        for(int i=n-2;i>=0;){
            if(mini<nums[i]){
                int gpd=fn(nums[i]);
                //cout<<gpd<<endl;
                if(gpd==1) return -1;
                nums[i]/=gpd;
                ans++;               
            }else{
                mini=nums[i];
                i--;
            }
        }
        return ans;
        
    }
};