class Solution {
public:
    //REFER TO THIS LINK FOR THE APPROACH:
    //https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/solutions/5783565/nakab-posh-question-chalo-deduce-kre-observation-ko
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=-1;
        for(int x:nums) mx=max(mx,x);
        int ans=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=mx) continue;
            else{
                int len=0;
                while(i<n&&nums[i]==mx){
                    len++;
                    ans=max(ans,len);
                    i++;
                }
                i--;
            }
        }
        return ans;
    }
};