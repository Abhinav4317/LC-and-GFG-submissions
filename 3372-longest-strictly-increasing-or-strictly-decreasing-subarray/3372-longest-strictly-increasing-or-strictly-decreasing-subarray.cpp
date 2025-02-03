class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int i=0,j=1;
        int ans=1,f=0;
        while(j<n){
            if(nums[j]==nums[i]){while(j<n&&nums[j]==nums[i]){i++;j++;}}
            else{
                if(f==0&&nums[j]>nums[i]){
                    while(j<n&&nums[j]>nums[j-1]) j++;
                    ans=max(ans,j-i);
                    i=j-1;
                    f=1;
                }
                else if(f==0&&nums[j]<nums[i]) {f=1;}
                else if(f==1&&nums[j]<nums[i]){
                    while(j<n&&nums[j]<nums[j-1]) j++;
                    ans=max(ans,j-i);
                    i=j-1;
                    f=0;
                }
                else if(f==1&&nums[j]>nums[i]){f=0;}
            }
        }
        return ans;
    }
};